firstDate = (*myIssues)[0]->GetStart();
lastDate = (*myIssues)[0]->GetEnd();

for (unsigned int i = 1; i < myIssues->size(); i++)
{
    if((*myIssues)[i]->GetStart() < firstDate)
        firstDate = (*myIssues)[i]->GetStart();
    if((*myIssues)[i]->GetEnd() > lastDate)
        lastDate = (*myIssues)[i]->GetEnd();
}

lastDate += wxTimeSpan::Days(6);
firstDate -= wxTimeSpan::Days(6);

while (lastDate.Subtract(firstDate).GetDays() < 62)
{
    lastDate += wxTimeSpan::Days(1);
    firstDate -= wxTimeSpan::Days(1);
}