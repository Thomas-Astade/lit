//~~ std::set<wxString> GetResourceTokens() [litIssueList] ~~
std::set<wxString> aSet;

for (std::list<litIssue*>::iterator it = myIssues.begin(); it != myIssues.end(); it++)
{
    if ((*it)->GetState()<=2)
    {
    	std::set<wxString> resourceSet = GetTokens((*it)->GetResource());
    	aSet.insert(resourceSet.begin(),resourceSet.end());
   	}
}

return aSet;