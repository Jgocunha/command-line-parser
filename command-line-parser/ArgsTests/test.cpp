#include "pch.h"

#include "args.h" // Assuming Args class is defined in a file called Args.h

TEST(ArgsTest, ConstructorTest)
{
    // Test case 1: valid schema and arguments
    std::vector<std::string> args1 = { "-b", "-s", "hello", "-i", "123" };
    Args argsObj1("b,s*,i#,", args1);
    ASSERT_TRUE(argsObj1.has('b'));
    ASSERT_EQ(argsObj1.getString('s'), "hello");
    ASSERT_EQ(argsObj1.getInt('i'), 123);

    // Test case 2: schema with missing argument identifier
    std::vector<std::string> args2 = { "-b", "-s", "world" };
    Args argsObj2("b,s*,i#,", args2);
    ASSERT_TRUE(argsObj2.has('b'));
    ASSERT_EQ(argsObj2.getString('s'), "world");
    ASSERT_EQ(argsObj2.getInt('i'), 0);

    // Test case 3: schema with missing required argument
    std::vector<std::string> args3 = { "-b", "-i", "456" };
    Args argsObj3("b,s*,i#,", args3);
    ASSERT_TRUE(argsObj3.has('b'));
    ASSERT_EQ(argsObj3.getString('s'), "");
    ASSERT_EQ(argsObj3.getInt('i'), 456);

    // Test case 4: schema with unexpected argument
    std::vector<std::string> args4 = { "-b", "-s", "hello", "-f", "invalid" };
    Args argsObj4("b,s*,i#,", args4);
    ASSERT_TRUE(argsObj4.has('b'));
    ASSERT_EQ(argsObj4.getString('s'), "hello");
    ASSERT_EQ(argsObj4.getInt('i'), 0);
}

#include "ArgsException.h" // Include the header file for ArgsException

// Test fixture for ArgsException
class ArgsExceptionTest : public ::testing::Test {
protected:
    ArgsException ex; // Instance of ArgsException for testing

    void SetUp() override {
        // Set up any common data or objects needed for the tests
    }
};

// Test case for ArgsException default constructor
TEST_F(ArgsExceptionTest, DefaultConstructor) {
    // Assert that the error argument ID is '\0'
    ASSERT_EQ(ex.getErrorArgumentId(), '\0');
    // Assert that the error parameter is empty
    ASSERT_EQ(ex.getErrorParameter(), "");
    // Assert that the error code is OK
    ASSERT_EQ(ex.getErrorCode(), ErrorCode::OK);
    // Assert that the error message is empty
    ASSERT_STREQ(ex.what(), "");
}

// Test case for ArgsException constructor with error message
TEST_F(ArgsExceptionTest, ConstructorWithMessage) {
    ArgsException ex("Test error message"); // Create ArgsException with error message

    // Assert that the error message matches the provided error message
    ASSERT_STREQ(ex.what(), "Test error message");
}

// Test case for ArgsException constructor with error code
TEST_F(ArgsExceptionTest, ConstructorWithErrorCode) {
    ArgsException ex(ErrorCode::UNEXPECTED_ARGUMENT); // Create ArgsException with error code

    // Assert that the error code matches the provided error code
    ASSERT_EQ(ex.getErrorCode(), ErrorCode::UNEXPECTED_ARGUMENT);
    // Assert that the error argument ID is '\0'
    ASSERT_EQ(ex.getErrorArgumentId(), '\0');
    // Assert that the error parameter is empty
    ASSERT_EQ(ex.getErrorParameter(), "");
    // Assert that the error message matches the expected error message
    ASSERT_STREQ(ex.what(), "Argument unexpected ");
}

// Test case for ArgsException constructor with error code and error parameter
TEST_F(ArgsExceptionTest, ConstructorWithErrorCodeAndErrorParameter) {
    ArgsException ex(ErrorCode::INVALID_ARGUMENT_FORMAT, "test_parameter"); // Create ArgsException with error code and error parameter

    // Assert that the error code matches the provided error code
    ASSERT_EQ(ex.getErrorCode(), ErrorCode::INVALID_ARGUMENT_FORMAT);
    // Assert that the error argument ID is '\0'
    ASSERT_EQ(ex.getErrorArgumentId(), '\0');
    // Assert that the error parameter matches the provided error parameter
    ASSERT_EQ(ex.getErrorParameter(), "test_parameter");
    // Assert that the error message matches the expected error message
    ASSERT_STREQ(ex.what(), "test_parameter is not a valid argument name.");
}

// Test case for ArgsException constructor with error code, error argument ID, and error parameter
TEST_F(ArgsExceptionTest, ConstructorWithErrorCodeArgumentIdAndErrorParameter) {
    ArgsException ex(ErrorCode::MISSING_DOUBLE, 'd', "test_parameter"); // Create ArgsException with error code, error argument ID, and error parameter

    // Assert that the error code matches the provided error code
    ASSERT_EQ(ex.getErrorCode(), ErrorCode::MISSING_DOUBLE);
    // Assert that the error argument ID matches the provided error argument ID
    ASSERT_EQ(ex.getErrorArgumentId(), 'd');
    // Assert that the error parameter matches the provided error parameter
    ASSERT_EQ(ex.getErrorParameter(), "test_parameter");
    // Assert that the error message matches the expected error message
    ASSERT_STREQ(ex.what(), "Could not find double parameter for d.");
}

#include "IntegerArgumentMarshaller.h"

TEST(IntegerArgumentMarshallerTest, TestSetValueAndGetVlaue)
{
    IntegerArgumentMarshaller integerArgMarshaller;
    std::vector<std::string> args = { "-i", "42" };

    // Test set() method
    integerArgMarshaller.set(args.begin()); 

    // Test getValue() method
    int value = integerArgMarshaller.getValue();
    EXPECT_EQ(value, 42);
}

TEST(IntegerArgumentMarshallerTest, TestSetMissingIntegerValue)
{
    IntegerArgumentMarshaller integerArgMarshaller;
    std::vector<std::string> args = { "-i", ""};

    // Test set() method with missing integer value
    try
    {
        std::vector<std::string>::iterator arg = args.begin(); 
        integerArgMarshaller.set(arg);
    }
    catch ( ArgsException& e)
    {
        EXPECT_EQ(e.getErrorCode(), INVALID_INTEGER);
        EXPECT_EQ(e.getErrorParameter(), "");
        return;
    }

    // If no exception is thrown, the test should fail
    FAIL() << "Expected ArgsException with error code INVALID_INTEGER.";
}

TEST(IntegerArgumentMarshallerTest, TestSetInvalidIntegerValue)
{
    IntegerArgumentMarshaller integerArgMarshaller;
    std::vector<std::string> args = { "-i", "invalid" };

    // Test set() method with invalid integer value
    try
    {
        integerArgMarshaller.set(args.begin());
    }
    catch (ArgsException& e)
    {
        EXPECT_EQ(e.getErrorCode(), INVALID_INTEGER);
        EXPECT_EQ(e.getErrorParameter(), "invalid");
        return;
    }

    // If no exception is thrown, the test should fail
    FAIL() << "Expected ArgsException with error code INVALID_INTEGER.";
}

TEST(IntegerArgumentMarshallerTest, TestGetValueWithoutSettingValue)
{
    IntegerArgumentMarshaller integerArgMarshaller;

    // Test getValue() method without setting a value
    int value = integerArgMarshaller.getValue();
    EXPECT_EQ(value, 0);
}