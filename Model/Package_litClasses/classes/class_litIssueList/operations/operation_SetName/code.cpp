if ((index >= static_cast<int>(myFilteredIssues.size())) || (index < 0))
    return;

myFilteredIssues[index]->SetName(name);
RefreshItem(index);