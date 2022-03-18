if (item < static_cast<int>(myFilteredIssues.size()))
    return myFilteredIssues[item]->GetState();

return 0;