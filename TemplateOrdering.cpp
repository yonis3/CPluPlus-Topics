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
