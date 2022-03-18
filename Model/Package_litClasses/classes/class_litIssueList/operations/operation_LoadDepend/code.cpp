wxString depend;
aConfig.Read("Depend",&depend,wxEmptyString);

wxStringTokenizer tkz(depend, ",");
while ( tkz.HasMoreTokens() )
{
    wxString token = tkz.GetNextToken();
    if (!token.empty())
    {
        unsigned long value;
        token.ToULong(&value);
        unsigned long i = 0;
        for (std::list<litIssue*>::iterator it = myIssues.begin(); it != myIssues.end(); it++)
            if (i++ == value)
                issue->SetDependency((*it), true);
    }
}



aConfig.SetPath("..");