if (index > static_cast<int>(myFilteredIssues.size()))
    return "error";

return myFilteredIssues[index]->GetResource();