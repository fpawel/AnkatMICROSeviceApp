object FormGrphSetsDlg: TFormGrphSetsDlg
  Left = 243
  Top = 125
  Width = 470
  Height = 312
  Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072
  Color = clWindow
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -10
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnActivate = FormActivate
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object grd1: TStringGrid
    Left = 0
    Top = 0
    Width = 462
    Height = 227
    Align = alClient
    BorderStyle = bsNone
    ColCount = 3
    DefaultColWidth = 150
    DefaultRowHeight = 23
    FixedCols = 0
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Arial'
    Font.Style = []
    GridLineWidth = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing, goEditing]
    ParentFont = False
    TabOrder = 0
    OnGetEditText = grd1GetEditText
    OnSelectCell = grd1SelectCell
    OnSetEditText = grd1SetEditText
    ColWidths = (
      260
      100
      83)
  end
  object Panel1: TPanel
    Left = 0
    Top = 227
    Width = 462
    Height = 51
    Align = alBottom
    BevelOuter = bvNone
    Color = clWindow
    TabOrder = 1
    object Button2: TButton
      Left = 157
      Top = 8
      Width = 136
      Height = 33
      Caption = #1054#1090#1084#1077#1085#1072
      TabOrder = 0
      OnClick = Button2Click
    end
    object Button1: TButton
      Left = 7
      Top = 8
      Width = 137
      Height = 33
      Caption = #1055#1088#1080#1084#1077#1085#1080#1090#1100
      TabOrder = 1
      OnClick = Button1Click
    end
  end
end
