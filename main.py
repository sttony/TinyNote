#!/bin/python
"""
main
"""

import wx


class MainFrame(wx.Frame):
    """
    A Frame that says Hello World
    """

    def __init__(self, *args, **kw):
        # ensure the parent's __init__ is called
        super(MainFrame, self).__init__(*args, **kw)

        tb = wx.ToolBar(self, -1)
        self.ToolBar = tb
        tb.AddTool(101, "Readonly", wx.Bitmap("./icons/xfce4-menueditor.png"))

        # create a panel in the frame
        pnl = wx.Panel(self)

        self.CreateStatusBar()
        self.SetStatusText("Welcome to wxPython!")

    def OnExit(self, event):
        """Close the frame, terminating the application."""
        self.Close(True)


if __name__ == '__main__':
    # When this module is run (not imported) then create the app, the
    # frame, show it, and start the event loop.
    app = wx.App()
    frm = MainFrame(None, title='TinyNote')
    frm.Show()
    app.MainLoop()
