if ((dependentIssue >= static_cast<int>(myFilteredIssues.size())) || (dependentIssue < 0))
    return false;

if ((dependentFrom >= static_cast<int>(myFilteredIssues.size())) || (dependentFrom < 0))
    return false;

return myFilteredIssues[dependentIssue]->GetIsDependent(myFilteredIssues[dependentFrom]);