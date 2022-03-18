if (index > static_cast<int>(myFilteredIssues.size()))
    return false;

return myFilteredIssues[index]->GetIsMilestone();