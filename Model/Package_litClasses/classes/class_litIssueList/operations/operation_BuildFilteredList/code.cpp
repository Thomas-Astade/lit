myFilteredIssues.clear();

for (std::list<litIssue*>::iterator it = myIssues.begin(); it != myIssues.end(); it++)
{
    if ((resourceFilterMatch((*it)->GetResource())) && (projectFilterMatch((*it)->GetProjects())))
    {
        if (((*it)->GetState()==0) && (filter & 1))
            myFilteredIssues.push_back(*it);
        else if (((*it)->GetState()==1) && (filter & 2))
            myFilteredIssues.push_back(*it);
        else if (((*it)->GetState()==2) && (filter & 4))
            myFilteredIssues.push_back(*it);
        else if (((*it)->GetState()==3) && (filter & 8))
            myFilteredIssues.push_back(*it);
        else if (((*it)->GetState()==4) && (filter & 16))
            myFilteredIssues.push_back(*it);
    }
}

SetItemCount(myFilteredIssues.size());
Refresh();