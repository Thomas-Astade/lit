if (index > static_cast<int>(myFilteredIssues.size()))
    return wxDateTime::Today();

return myFilteredIssues[index]->GetStart();