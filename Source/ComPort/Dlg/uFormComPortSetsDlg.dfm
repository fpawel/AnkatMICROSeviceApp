object FormComPortSetsDlg: TFormComPortSetsDlg
  Left = 487
  Top = 165
  BorderStyle = bsDialog
  Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072
  ClientHeight = 200
  ClientWidth = 288
  Color = clBtnFace
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
  object Label1: TLabel
    Left = 7
    Top = 2
    Width = 52
    Height = 13
    Caption = 'COM '#1055#1086#1088#1090
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Button1: TButton
    Left = 189
    Top = 7
    Width = 91
    Height = 33
    Caption = #1055#1088#1080#1084#1077#1085#1080#1090#1100
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 189
    Top = 46
    Width = 91
    Height = 33
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 1
    OnClick = Button2Click
  end
  object edSilentTime: TLabeledEdit
    Left = 7
    Top = 137
    Width = 162
    Height = 24
    EditLabel.Width = 246
    EditLabel.Height = 13
    EditLabel.Caption = #1044#1083#1080#1090#1077#1083#1100#1085#1086#1089#1090#1100' '#1086#1078#1080#1076#1072#1085#1080#1103' '#1089#1080#1084#1074#1086#1083#1072' '#1087#1088#1080#1105#1084#1072', '#1084#1089#1077#1082
    EditLabel.Font.Charset = DEFAULT_CHARSET
    EditLabel.Font.Color = clNavy
    EditLabel.Font.Height = -12
    EditLabel.Font.Name = 'MS Sans Serif'
    EditLabel.Font.Style = []
    EditLabel.ParentFont = False
    EditLabel.WordWrap = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    LabelPosition = lpAbove
    LabelSpacing = 3
    ParentFont = False
    TabOrder = 2
    OnExit = edKanalExit
  end
  object edWriteDelay: TLabeledEdit
    Left = 7
    Top = 98
    Width = 162
    Height = 24
    EditLabel.Width = 133
    EditLabel.Height = 13
    EditLabel.Caption = #1047#1072#1076#1077#1088#1078#1082#1072' '#1086#1090#1087#1088#1072#1074#1082#1080', '#1084#1089#1077#1082
    EditLabel.Font.Charset = DEFAULT_CHARSET
    EditLabel.Font.Color = clNavy
    EditLabel.Font.Height = -12
    EditLabel.Font.Name = 'MS Sans Serif'
    EditLabel.Font.Style = []
    EditLabel.ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    LabelPosition = lpAbove
    LabelSpacing = 3
    ParentFont = False
    TabOrder = 3
    OnExit = edKanalExit
  end
  object edTimeOut: TLabeledEdit
    Left = 7
    Top = 59
    Width = 162
    Height = 24
    EditLabel.Width = 112
    EditLabel.Height = 13
    EditLabel.Caption = #1058#1072#1081#1084#1072#1091#1090' '#1086#1090#1074#1077#1090#1072', '#1084#1089#1077#1082
    EditLabel.Font.Charset = DEFAULT_CHARSET
    EditLabel.Font.Color = clNavy
    EditLabel.Font.Height = -12
    EditLabel.Font.Name = 'MS Sans Serif'
    EditLabel.Font.Style = []
    EditLabel.ParentFont = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    LabelPosition = lpAbove
    LabelSpacing = 3
    ParentFont = False
    TabOrder = 4
    OnExit = edKanalExit
  end
  object cbPortName: TComboBox
    Left = 7
    Top = 20
    Width = 163
    Height = 24
    Style = csOwnerDrawVariable
    ItemHeight = 18
    TabOrder = 5
  end
  object edRepeatCount: TLabeledEdit
    Left = 7
    Top = 176
    Width = 163
    Height = 24
    EditLabel.Width = 154
    EditLabel.Height = 13
    EditLabel.Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1087#1086#1074#1090#1086#1088#1086#1074' '#1079#1072#1087#1088#1086#1089#1072
    EditLabel.Font.Charset = DEFAULT_CHARSET
    EditLabel.Font.Color = clNavy
    EditLabel.Font.Height = -11
    EditLabel.Font.Name = 'MS Sans Serif'
    EditLabel.Font.Style = []
    EditLabel.ParentFont = False
    LabelPosition = lpAbove
    LabelSpacing = 3
    TabOrder = 6
    OnExit = edKanalExit
  end
end
