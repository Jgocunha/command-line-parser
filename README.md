# command-line-parser
Case study of a commnad-line argument parser as seen in Clean Code Chapter 14 - Sucessive refinement. (Difference is, it is implemented in C++)

---

## Syntax guidelines

---

## Refactoring guidelines

*”I compiled this list by walking through several different programs and refactoring them. As I made each change, I
asked myself why I made that change and then wrote the reason. The result is a rather long list of thing that ’smells
bad’ to me when I read code.* Clean Code - Martin

### Names

**Use explanatory variables**

One of the most powerful ways to make a program readable is to break calculations up into intermediate values that are held in variables with meaningful names.

**Replace magic numbers with named constants**

In general, it is a bad idea to have raw members in your code. You should hide them behind well-named constants. However, some constants are so easy to recognize that they do not always need a named constant to hide behind. 

**Choose descriptive names**

**Choose names at the appropriate level of abstraction**

**Use standard nomenclature when possible**

**Unambigous names**

Choose names that make the workings of a function or variable unambiguous.

```
    string doRename()
    {
        // ...
        if(request)
            renameRequest();
        renamePage();
        //...
    }
```

The name of this function says what it does in a broad and vague way. Emphasized by the ```renamePage()``` function call. One could ask what is the difference between the two?

**Use long names for long scopes**

The length of a name should be related to the length of the scope.

**Avoid encondings**

Prefixes such as ```m_``` are useless nowadays.

**Names should describe side-effects**

Names should describe everything that a function, variable, or class does.

---

### Formatting

**Vertical separation**

**Variables and functions** should be defined closer to where they are used. **Local variables** should be declared just above their first usage and should have a small vertical scope. **Private functions** should be defined just below their first usage.

**Inconsistency**

If you do something a certain way, do all similar thongs in the same way.

---

### Comments

**Innapropriate information**

It is inappropriate for a comment to hold information better held in a different kind of system, e.g., source code control system, authors, last modified date, etc.

**Obsolete comments**

It is best not to write a comment that will become obsolete.

**Redundant comment**

A comment is redundant it it describes something that already adequately describes itself. Comments should say things that the code cannot say for itself. E.g.:

```
i++; //increment i
```

**Poorlty written comment**

A comment worth writing is worth writing well. Use correct grammar and punctuation, be brief, etc.

**Commented out code**

Commented-out code tends to sit and rot. If you want old code use source control.

---

### Functions

**Too many arguments**

No argument is best! Followed by 1, 2, 3. 3 or more is questionable and should be avoided with prejudice.

**Output arguments**

Output arguments are counter-intuitive,

**Flag arguments**

Boolean arguments loudly declare that the function does not do one thing. It does one thing if ```true``` or the other if ```false```.

**Selector arguments**

There is hardly anything more abominable than dangling ```false``` arguments at the end of a function call, e.g. ```calculateWeeklyPay(false);``` what does it mean? Selector arguments are just a lazy way to avoid splitting a large function into several smaller ones.

**Dead function**

Delete functions that are not called.

**Functions should do one thing**

**Hidden temporal couplings**

Temporal couplings are often necessary, but you should not hide them. Structure the arguments of your functions such that the order in which they should be called is obvious.

```
    void dive (const string& reason)
    {
        //each function produces a result that the next function needs
        Gradient gradient = saturateGradient();
        List<spline> splines = reticulateSplines(gradients);
        diveForMoog(splines, reason);
    }
```

**Functions should descend only one level of abstraction**

The statements within a function should all be written at the same level of abstraction, which should be one level below the operation described by the name of the function.

**Innapropriate static**

In general, you should prefer non-static methods. When in doubt make the function non-station. If you really want a function to be static, make sure that there is no chance that you will want it to behave polymorphically.

---

### Classes

**Code at the wrong level of abstraction**

Create abstractions that separate higher-level general concepts from lower-level detailed concepts. Create abstract classes to hold the higher-level concepts and derivatives to hold the lower-level concepts.

**Ban class depending on their derivatives**

The most common reason for partitioning concepts into base and derivative classes is so that the higher-level concepts can be independent of the lower-level derivative class concepts. Therefore, when we see base classes mentioning the names of their derivatives we suspect a problem.

**Too much information**

Well-defined modules have very small interfaces that allow you to do a lot with little. Poorly defined modules have deep interfaces that force you to use many different methods to get simple things done. The fewer methods a class has, the better.

**Feature envy**

The methods of a class should be interested in the variables and functions of the class they belong to, and not the variables and functions of other classes. When a method uses accessors and mutators of some other object to manipulate the data within that object, then it envies the scope of the class of that other object.


```    
class HourlyPayCalculator
    {
        Money calculateWeeklyPay (HourlyEmployee e)
        {
            int tenthRate = e.getTenthRate().getPennies();
            //...
        }

    }
```

The ```calculateWeeklyPay``` method reaches into the ```HourlyEmployee``` object to get data. So it envies the scope of ```HourlyEmployee```. We want to eliminate feature envy because it exposes the internals of one class to another. Sometimes, however, it is a necessary evil.

**Make logical dependencies physical**

If one module depends on another, that dependency should be physical, not just logical.

**Prefer polymorphism to if/else or switch/case**

Most people use ```switch``` because it is the obvious brute force solution. The cases where functions are more volatile than types are rare. 

"The one switch rule": There may be no more than one ```switch``` statement for a given type of selection. The cases in that ```swicth``` must create polymorphic objects that take the place of other ```switch``` statements in the rest of the system.


**Avoid transitive navigation**

In general, we do not want a single module to know much about its collaborators. More specifically, if A collaborates with B, and B collaborates with C, we do not want models that use A to know about C. We don't want ```a.getB().getC().doSomething()```.

This is called "The Law of Demeter" or "Writing shy code". Make sure that, modules know only about their immediate collaborators and not the navigation map of the whole system.

---

### General

**Obvious behaviour is unimplemented**

Any function or class should implement the behaviours that another programmer reasonably expects.

**Duplication**

"Do not repeat yourself.", "Once, and once only." Every time you see duplication in the code, it represents an opportunity for abstraction.

**Dead code**

Dead code is code that is not executed. You find it in an ```if else```, in a ```try catch```, ```switch case```...

**Clutter**

Of what use is a default constructor with no implementation? Clutter!

**Artificial coupling**

Artificial coupling is a coupling between modules that serves no direct purpose, It is a result of putting a variable, etc. in a temporarily convenient though inappropriate location.

**Obscured intent**

We want code to be as expressive as possible. As small and dense as code can be, it might also become impenetrable.

```    
int m_otCalc()
    {
        /...
        return thsWkd.thsVal();
    }
```

**Misplaced responsibility**

E.g. where should the ```PI``` constant go? Math class? Trigonometry class? Circle class?

The principle of least surprise comes into play here, *i.e.*, code should go where the using functions are declared.


**Understand the algorithm**

The best way to understand how a function works is by refactoring it.


**Follow standard conventions**


**Encapsulate conditionals**

Extract functions that explain the intent of the conditional.

```
    if(shouldBeDeleted(timer)); //Vs.
    if(timer.hasExpired() && !timer.isAlive());
```

**Avoid negative conditionals**

```
    if(shouldBeDeleted(timer)); //Vs.
    if(!shouldBeDeleted(timer));
```


**Do not be arbitrary**

Have a reason for the way you structure your code, and make sure that reason is communicated by the structure of the code.

**Encapsulate boundary conditions**

Boundary conditions are hard to keep track of. Put the processing for them in one place, we do not want to swarm the code of ```+1```'s and ```-1```'s.

```
    if(level + 1 < tags.length())
    {
        parts(level + 1);
    } // Vs.
    int nextLevel = level + 1;
    if(nextLevel < tags.length())
    {
        parts(nextLevel);
    }
```

**Keep configurable data at high levels**

If you have a constant that is known and expected at a high level of abstraction do not bury it in a low-level function. Expose it as an argument to that low-level function called from the higher-level function.

```
    public static void main (String[] args)
    {
        Arguments arguments = parseCommandLine(args);
        //...
    }
    class Arguments
    {
        public:
            static string DEFAULT_PATH = ".";
            static string DEFAULT_ROOT = "FitnesseRoot";
        //...
    }
```

The configuration constants reside at the highest level and are easy to change. They get passed down to the rest of the application.

---

### Tests

**Insufficient tests**

Tests are insufficient so as long there are conditions that have been explored by the tests or calculations that have not been validated.

**Use a coverage tool**

**Do not skip trivial tests**

**An ignored test is a question about an ambiguity**

**Test boundary conditions**

**Patterns of failure are revealing**

**Test coverage patterns can be revealing**

**Tests should be fast**
