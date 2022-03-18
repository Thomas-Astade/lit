for (std::list<litIssue*>::iterator it = myIssues.begin(); it != myIssues.end(); it++)
{
    if (((*it)->GetState() != 3) && ((*it)->GetState() != 4))
        (*it)->SetState((*it)->GetState());
}