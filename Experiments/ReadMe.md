###Exp1-[CRTP](https://en.wikipedia.org/wiki/Curiously_recurring_template_pattern)
- This is called the Curiously Recurring Template Pattern, or CRTP for short.   
- Achieve the effect of static polymorphism by taking advantage 
of the fact that by the time 
- you get to MyTemplate<MyClass> in the line class MyClass : public MyTemplate<MyClass>, 
MyClass is semi-defined (it is an incomplete type) so you can store pointers to that type, etc, 
and do things with it that do not require a complete type.