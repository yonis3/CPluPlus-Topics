template<typename C>
bool operator<(const String<C>& s1, const String<C>& s2)
{
static_assert(Ordered<C>(),"String's character type not ordered");
bool eq = true;
for (int i=0; i!=s1.size() && i!=s2.size(); ++i) {
if (s2[i]<s1[i]) return false;
if (s1[i]<s2[i]) eq = false; // not s1==s2
}
if (s2.size()<s1.siz e()) return false; // s2 is shorter than s1
if (s1.size()==s2.siz e() && eq) return false; // s1==s2
return true;
}

/*a way to formally specify and test the semantics of move operations in C++ using code rather than informal comments. By representing these axioms as executable code, you make them more concrete and amenable to automated testing, which can help ensure that move operations behave as expected.

Here's a summary of the axioms you've described:

A move operation yields a value that compares equal to whatever the source of the move operation compared equal to.
The source of the move operation can be destroyed.
By expressing these axioms in code, you create a more precise and testable specification for move semantics. This can be particularly valuable when working on complex codebases or libraries where you want to ensure that move operations are implemented correctly and consistently.

While expressing such axioms in code may require more effort than writing informal comments, the benefits include increased clarity, the ability to automate testing, and the ability to catch potential issues early in the development process. Using formal logic or code-based specifications can be especially valuable when working on critical or high-assurance systems
*/
