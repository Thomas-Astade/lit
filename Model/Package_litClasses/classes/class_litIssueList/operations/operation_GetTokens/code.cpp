//~~ std::set<wxString> GetTokens(wxString tokenStr) [litIssueList] ~~
tokenStr.MakeUpper();

wxStringTokenizer aTokenizer(tokenStr,"\t\r\n ,");

std::set<wxString> aSet;

while (aTokenizer.HasMoreTokens())
{
    wxString nextToken = aTokenizer.GetNextToken();
    nextToken.Trim(true).Trim(false);
    if (!nextToken.empty())
        aSet.insert(nextToken);
}
    
return aSet;