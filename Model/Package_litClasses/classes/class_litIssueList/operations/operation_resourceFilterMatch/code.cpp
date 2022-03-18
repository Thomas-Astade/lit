if (resourceFilter.empty())
    return true;

std::set<wxString> aSet = GetTokens(aList);

if (aSet.empty())
    return true;
    
for (std::set<wxString>::iterator it = aSet.begin(); it != aSet.end(); it++)
    if (resourceFilter.find(*it)!=resourceFilter.end())
        return true;

return false;