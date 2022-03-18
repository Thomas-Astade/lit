//~~ litFrame() [litFrame] ~~
milestoneListCtrl->Init();

mainFrame_menubar->GetMenu(0)->Append(ID_New,"New","", wxITEM_NORMAL);
mainFrame_menubar->GetMenu(0)->Append(ID_Open,"Open","", wxITEM_NORMAL);
mainFrame_menubar->GetMenu(0)->Append(ID_Save,"Save","", wxITEM_NORMAL);
mainFrame_menubar->GetMenu(0)->AppendSeparator();
mainFrame_menubar->GetMenu(0)->Append(ID_SaveAs,"Save as ...","", wxITEM_NORMAL);
mainFrame_menubar->GetMenu(0)->AppendSeparator();
mainFrame_menubar->GetMenu(0)->Append(ID_SaveGantt,"Save Gantt as ...","", wxITEM_NORMAL);
mainFrame_menubar->GetMenu(0)->Append(ID_SaveTrend,"Save Trend as ...","", wxITEM_NORMAL);

mainFrame_menubar->GetMenu(1)->Append(ID_About,"about","", wxITEM_NORMAL);

issueGantt->SetIssues(milestoneListCtrl->GetFilteredIssues());
issueTrend->SetIssues(milestoneListCtrl->GetFilteredIssues());
