#pragma once

#include <string>

enum ErrorCode 
{
	OK, INVALID_ARGUMENT_FORMAT, UNEXPECTED_ARGUMENT, INVALID_ARGUMENT_NAME,
	MISSING_STRING,
	MISSING_INTEGER, INVALID_INTEGER,
	MISSING_DOUBLE, INVALID_DOUBLE
};


class ArgsException : public std::exception
{
private:
	char errorArgumentId;
	std::string errorParameter;
	ErrorCode errorCode;
	std::string errorMessage;
public:
	ArgsException()
	{
		errorArgumentId = '\0';
		errorParameter = {};
		errorCode = OK;
		errorMessage = "";
	}
	ArgsException(const std::string& message)
	{
		errorMessage = message;
	}
	ArgsException(const ErrorCode errorCode)
	{
		this->errorCode = errorCode;
		errorArgumentId = '\0';
		errorMessage = getErrorMessage();
	}
	ArgsException(const ErrorCode errorCode, const std::string& errorParameter)
	{
		this->errorCode = errorCode;
		this->errorParameter = errorParameter;
		errorMessage = getErrorMessage();
	}
	ArgsException(const ErrorCode errorCode, const char errorArgumentId, const std::string& errorParameter = "")
	{
		this->errorCode = errorCode;
		this->errorArgumentId = errorArgumentId;
		this->errorParameter = errorParameter;
		errorMessage = getErrorMessage();
	}

	const char* what() const noexcept override {
		return errorMessage.c_str();
	}

	char getErrorArgumentId() {
		return errorArgumentId;
	}

	void setErrorArgumentId(const char errorArgumentId) {
		this->errorArgumentId = errorArgumentId;
	}

	std::string getErrorParameter() {
		return errorParameter;
	}

	void setErrorParameter(const std::string& errorParameter) {
		this->errorParameter = errorParameter;
	}

	ErrorCode getErrorCode() {
		return errorCode;
	}

	void setErrorCode(ErrorCode errorCode) {
		this->errorCode = errorCode;
	}

	std::string getErrorMessage()
	{

		switch (errorCode)
		{
		case OK:
			errorMessage = "TILT: Should not get here.";
			break;
		case UNEXPECTED_ARGUMENT:
			errorMessage = "Argument " + std::string(1, errorArgumentId) + " unexpected.";
			break;
		case MISSING_STRING:
			errorMessage = "Could not find string parameter for " + std::string(1, errorArgumentId) + ".";
			break;
		case INVALID_INTEGER:
			errorMessage = "Argument " + std::string(1, errorArgumentId) + " expects an integer but was " + errorParameter + " .";
			break;
		case INVALID_DOUBLE:
			errorMessage = "Argument " + std::string(1, errorArgumentId) + " expects a double but was " + errorParameter + " .";
			break;
		case MISSING_DOUBLE:
			errorMessage = "Could not find double parameter for " + std::string(1, errorArgumentId) + ".";
			break;
		case INVALID_ARGUMENT_NAME:
			errorMessage = std::string(1, errorArgumentId) + " is not a valid argument name.";
			break;
		case INVALID_ARGUMENT_FORMAT:
			errorMessage = errorParameter + " is not a valid argument name.";
			break;
		default:
			errorMessage = "An error was detected but no suitable response was found!";
			break;
		}
		return errorMessage;
	}
};