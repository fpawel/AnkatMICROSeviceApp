object FormGridColsDlg: TFormGridColsDlg
  Left = 200
  Top = 136
  Width = 413
  Height = 350
  BorderIcons = [biSystemMenu]
  Caption = #1042#1099#1073#1080#1088#1080#1090#1077' '#1074#1080#1076#1080#1084#1099#1077' '#1089#1090#1086#1083#1073#1094#1099' '#1090#1072#1073#1083#1080#1094#1099
  Color = clWindow
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clNavy
  Font.Height = -15
  Font.Name = 'Arial'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 17
  object clb: TCheckListBox
    Left = 0
    Top = 0
    Width = 405
    Height = 316
    OnClickCheck = clbClickCheck
    Align = alClient
    BevelInner = bvNone
    BevelOuter = bvNone
    BorderStyle = bsNone
    ItemHeight = 25
    Items.Strings = (
      #1057#1090#1086#1083#1073#1077#1094'1'
      #1057#1090#1086#1083#1073#1077#1094'2'
      #1057#1090#1086#1083#1073#1077#1094'3'
      #1057#1090#1086#1083#1073#1077#1094'4'
      #1057#1090#1086#1083#1073#1077#1094'5'
      #1057#1090#1086#1083#1073#1077#1094'6'
      #1057#1090#1086#1083#1073#1077#1094'7')
    ParentColor = True
    Style = lbOwnerDrawFixed
    TabOrder = 0
    OnKeyDown = clbKeyDown
  end
end
