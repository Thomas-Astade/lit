if ((index >= static_cast<int>(myFilteredIssues.size())) || (index < 0))
   return;

myFilteredIssues[index]->SetEnd(aDate);
RefreshItem(index);