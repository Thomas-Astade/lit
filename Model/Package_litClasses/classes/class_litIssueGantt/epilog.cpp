BEGIN_EVENT_TABLE(litIssueGantt, litGantt)
  EVT_PAINT(litIssueGantt::OnPaint)
  EVT_LEFT_DOWN(litIssueGantt::MouseClicked)
  EVT_MOTION(litIssueGantt::MouseMotion)
  EVT_ENTER_WINDOW(litIssueGantt::MouseEnterLeave)
  EVT_LEAVE_WINDOW(litIssueGantt::MouseEnterLeave)
END_EVENT_TABLE()
