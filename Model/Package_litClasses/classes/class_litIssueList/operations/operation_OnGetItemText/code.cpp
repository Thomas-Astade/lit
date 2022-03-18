if (item < static_cast<int>(myFilteredIssues.size()))
switch (column)
{
    case 0:
        return myFilteredIssues[item]->GetName();
    break;
    case 1:
        return myFilteredIssues[item]->GetEnd().FormatISODate();
    break;
    case 2:
        return myFilteredIssues[item]->GetProjects();
    break;
    case 3:
        return myFilteredIssues[item]->GetResource();
    break;
}

return "error";