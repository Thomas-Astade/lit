if ((dependentIssue >= static_cast<int>(myFilteredIssues.size())) || (dependentIssue < 0))
    return;

if ((dependentFrom >= static_cast<int>(myFilteredIssues.size())) || (dependentFrom < 0))
    return;

myFilteredIssues[dependentIssue]->SetDependency(myFilteredIssues[dependentFrom],dependency);