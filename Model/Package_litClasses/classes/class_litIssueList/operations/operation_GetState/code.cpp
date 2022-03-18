if (index > static_cast<int>(myFilteredIssues.size()))
    return 0;

return myFilteredIssues[index]->GetState();