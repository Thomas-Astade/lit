if (projectFilter.empty())
    return true;

std::set<wxString> aSet = GetTokens(aList);

if (aSet.empty())
    return true;
    
for (std::set<wxString>::iterator it = aSet.begin(); it != aSet.end(); it++)
    if (projectFilter.find(*it)!=projectFilter.end())
        return true;

return false;