import static com.objectmentor.utilities.args.ArgsException.ErrorCode.*;

import java.rmi.AccessException;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class StringArgumentMarshaller implements ArgumentMarshaller {
    private String stringValue = "";

    public void set(Iterator<String> currentArgument) throws ArgsException {
        try {
            stringValue = currentArgument.next();
        } catch (NoSuchElementException e) {
            throw new ArgsException(MISSING_STRING);
        }
    }

    public static String getValue(ArgumentMarshaller am) {
        if (am != null && am instanceof StringArgumentMarshaller)
            return ((StringArgumentMarshaller) am).stringValue;
        else
            return "";
    }
}
