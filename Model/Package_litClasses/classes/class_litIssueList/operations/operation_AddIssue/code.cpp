wxTextEntryDialog aDialog(this, "Issue name:", "new issue");
if (aDialog.ShowModal() == wxID_OK)
{
    litIssue* aIssue = new litIssue(aDialog.GetValue());
    aIssue->SetEnd(aIssue->GetStart()+wxTimeSpan::Days(7)); 
    myIssues.push_back(aIssue);
    BuildFilteredList();
}