Spear
=====

A simple yet comprehensive and versatile PEG (Parsing Expression Grammar) library for C++.

Latest stable release: N/A

Latest release: 0.1.0-alpha

Documentation
=============

API
---

###Example usage

```cpp
#include "spear.hpp"

Parser p = new Parser();
p.addPattern("myOtherPattern");
p.rule("root") >> "%string_literal" >> "$\\d\\w regex" >> "#label:%literal" >> "myOtherPattern?";
p.rule("myOtherPattern") >> "%literal2" >> more stuff... ;
SpearStructure s = p.parsefile("myfile.extension");
if(s.type == TEXT)
{
  cout << s.elements[0].text;
}
if(s.type == HASH)
{
  for(int i = 0; i <= MAX_SIZE; i++)
  {
    if(s.elements[i].child != NULL) cout << s.elements[i].name;
  }
}
```

Rule syntax
-----------

###String Literals

`"%string literal"`

###Regexes

`"$regex"`

###Labels

Allow that element to be accessed by its name.

`"#label:%literal"` or `"#label:$regex"`

###Subpatterns

`subpattern` or `subpattern?` or `subpattern*` or `subpattern+` or `subpattern{2,5}`

###Or statement

`subpattern1 | subpattern2` (spaces optional)
