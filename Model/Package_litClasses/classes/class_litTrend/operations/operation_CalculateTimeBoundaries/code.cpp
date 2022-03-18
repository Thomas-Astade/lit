firstDate = (*myIssues)[0]->GetEnd();
lastDate = (*myIssues)[0]->GetEnd();

for (unsigned int i = 0; i < myIssues->size(); i++)
{
    std::map<wxDateTime,wxDateTime> aChangeList = (*myIssues)[i]->GetChangeList();
    for (std::map<wxDateTime,wxDateTime>::iterator it = aChangeList.begin();
        it != aChangeList.end(); it++)
    {
        if((*it).first < firstDate)
            firstDate = (*it).first;
        if((*it).second < firstDate)
            firstDate = (*it).second;
        if((*it).first > lastDate)
            lastDate = (*it).first;
        if((*it).second > lastDate)
            lastDate = (*it).second;
    }
}

lastDate += wxTimeSpan::Days(6);
firstDate -= wxTimeSpan::Days(6);

while (lastDate.Subtract(firstDate).GetDays() < 62)
{
    lastDate += wxTimeSpan::Days(1);
    firstDate -= wxTimeSpan::Days(1);
}