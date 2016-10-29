object FormTest1: TFormTest1
  Left = 542
  Top = 321
  Width = 337
  Height = 206
  Caption = #1058#1077#1089#1090#1099
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 329
    Height = 172
    ActivePage = TabSheet2
    Align = alClient
    TabIndex = 0
    TabOrder = 0
    object TabSheet2: TTabSheet
      Caption = #1063#1072#1089#1086#1074#1072#1103' '#1080#1089#1090#1086#1088#1080#1103
      ImageIndex = 1
      object LabeledEdit6: TLabeledEdit
        Left = 88
        Top = 24
        Width = 57
        Height = 21
        EditLabel.Width = 47
        EditLabel.Height = 13
        EditLabel.Caption = #1048#1085#1076#1077#1082#1089' 1'
        EditLabel.Font.Charset = DEFAULT_CHARSET
        EditLabel.Font.Color = clNavy
        EditLabel.Font.Height = -11
        EditLabel.Font.Name = 'MS Sans Serif'
        EditLabel.Font.Style = []
        EditLabel.ParentFont = False
        LabelPosition = lpAbove
        LabelSpacing = 3
        TabOrder = 0
      end
      object LabeledEdit5: TLabeledEdit
        Left = 16
        Top = 24
        Width = 57
        Height = 21
        EditLabel.Width = 47
        EditLabel.Height = 13
        EditLabel.Caption = #1048#1085#1076#1077#1082#1089' 0'
        EditLabel.Font.Charset = DEFAULT_CHARSET
        EditLabel.Font.Color = clNavy
        EditLabel.Font.Height = -11
        EditLabel.Font.Name = 'MS Sans Serif'
        EditLabel.Font.Style = []
        EditLabel.ParentFont = False
        LabelPosition = lpAbove
        LabelSpacing = 3
        TabOrder = 1
      end
      object Button4: TButton
        Left = 232
        Top = 24
        Width = 81
        Height = 25
        Caption = #1057#1095#1080#1090#1072#1090#1100
        TabOrder = 2
        OnClick = Button4Click
      end
      object DateTimePicker1: TDateTimePicker
        Left = 144
        Top = 64
        Width = 73
        Height = 21
        CalAlignment = dtaLeft
        Date = 40826.4177985648
        Format = 'HH:mm'
        Time = 40826.4177985648
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkTime
        ParseInput = False
        TabOrder = 3
      end
      object DateTimePicker2: TDateTimePicker
        Left = 144
        Top = 96
        Width = 73
        Height = 21
        CalAlignment = dtaLeft
        Date = 40826.4177985648
        Format = 'HH:mm'
        Time = 40826.4177985648
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkTime
        ParseInput = False
        TabOrder = 4
      end
      object Button1: TButton
        Left = 232
        Top = 64
        Width = 81
        Height = 25
        Caption = #1055#1086#1080#1089#1082
        TabOrder = 5
        OnClick = Button1Click
      end
      object DateTimePicker5: TDateTimePicker
        Left = 16
        Top = 64
        Width = 121
        Height = 21
        CalAlignment = dtaLeft
        Date = 40826.4177985648
        Format = 'dd MMMM yyyy'
        Time = 40826.4177985648
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkDate
        ParseInput = False
        TabOrder = 6
      end
      object DateTimePicker6: TDateTimePicker
        Left = 16
        Top = 96
        Width = 121
        Height = 21
        CalAlignment = dtaLeft
        Date = 40826.4177985648
        Format = 'dd MMMM yyyy'
        Time = 40826.4177985648
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkDate
        ParseInput = False
        TabOrder = 7
      end
    end
    object TabSheet3: TTabSheet
      Caption = #1052#1080#1085#1091#1090#1085#1072#1103' '#1080#1089#1090#1086#1088#1080#1103
      ImageIndex = 2
      object Button2: TButton
        Left = 232
        Top = 64
        Width = 81
        Height = 25
        Caption = #1055#1086#1080#1089#1082
        TabOrder = 0
        OnClick = Button1Click
      end
      object Button3: TButton
        Left = 232
        Top = 24
        Width = 81
        Height = 25
        Caption = #1057#1095#1080#1090#1072#1090#1100
        TabOrder = 1
        OnClick = Button4Click
      end
      object LabeledEdit7: TLabeledEdit
        Left = 88
        Top = 24
        Width = 57
        Height = 21
        EditLabel.Width = 47
        EditLabel.Height = 13
        EditLabel.Caption = #1048#1085#1076#1077#1082#1089' 1'
        EditLabel.Font.Charset = DEFAULT_CHARSET
        EditLabel.Font.Color = clNavy
        EditLabel.Font.Height = -11
        EditLabel.Font.Name = 'MS Sans Serif'
        EditLabel.Font.Style = []
        EditLabel.ParentFont = False
        LabelPosition = lpAbove
        LabelSpacing = 3
        TabOrder = 2
      end
      object LabeledEdit8: TLabeledEdit
        Left = 16
        Top = 24
        Width = 57
        Height = 21
        EditLabel.Width = 47
        EditLabel.Height = 13
        EditLabel.Caption = #1048#1085#1076#1077#1082#1089' 0'
        EditLabel.Font.Charset = DEFAULT_CHARSET
        EditLabel.Font.Color = clNavy
        EditLabel.Font.Height = -11
        EditLabel.Font.Name = 'MS Sans Serif'
        EditLabel.Font.Style = []
        EditLabel.ParentFont = False
        LabelPosition = lpAbove
        LabelSpacing = 3
        TabOrder = 3
      end
      object DateTimePicker3: TDateTimePicker
        Left = 16
        Top = 64
        Width = 121
        Height = 21
        CalAlignment = dtaLeft
        Date = 40826.4177985648
        Format = 'dd MMMM yyyy'
        Time = 40826.4177985648
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkDate
        ParseInput = False
        TabOrder = 4
      end
      object DateTimePicker4: TDateTimePicker
        Left = 16
        Top = 96
        Width = 121
        Height = 21
        CalAlignment = dtaLeft
        Date = 40826.4177985648
        Format = 'dd MMMM yyyy'
        Time = 40826.4177985648
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkDate
        ParseInput = False
        TabOrder = 5
      end
      object DateTimePicker7: TDateTimePicker
        Left = 144
        Top = 96
        Width = 73
        Height = 21
        CalAlignment = dtaLeft
        Date = 40826.4177985648
        Format = 'HH:mm'
        Time = 40826.4177985648
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkTime
        ParseInput = False
        TabOrder = 6
      end
      object DateTimePicker8: TDateTimePicker
        Left = 144
        Top = 64
        Width = 73
        Height = 21
        CalAlignment = dtaLeft
        Date = 40826.4177985648
        Format = 'HH:mm'
        Time = 40826.4177985648
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkTime
        ParseInput = False
        TabOrder = 7
      end
    end
    object TabSheet1: TTabSheet
      Caption = #1048#1085#1076#1077#1082#1089#1099
      object SpeedButton1: TSpeedButton
        Left = 288
        Top = 32
        Width = 23
        Height = 22
        OnClick = SpeedButton1Click
      end
      object SpeedButton2: TSpeedButton
        Left = 288
        Top = 80
        Width = 23
        Height = 22
        OnClick = SpeedButton2Click
      end
      object LabeledEdit1: TLabeledEdit
        Left = 16
        Top = 32
        Width = 121
        Height = 21
        EditLabel.Width = 62
        EditLabel.Height = 13
        EditLabel.Caption = #1063#1072#1089', '#1080#1085#1076#1077#1082#1089
        EditLabel.Font.Charset = DEFAULT_CHARSET
        EditLabel.Font.Color = clNavy
        EditLabel.Font.Height = -11
        EditLabel.Font.Name = 'MS Sans Serif'
        EditLabel.Font.Style = []
        EditLabel.ParentFont = False
        LabelPosition = lpAbove
        LabelSpacing = 3
        TabOrder = 0
      end
      object LabeledEdit2: TLabeledEdit
        Left = 152
        Top = 32
        Width = 121
        Height = 21
        EditLabel.Width = 81
        EditLabel.Height = 13
        EditLabel.Caption = #1063#1072#1089', '#1080#1085#1082#1088#1077#1084#1077#1085#1090
        EditLabel.Font.Charset = DEFAULT_CHARSET
        EditLabel.Font.Color = clNavy
        EditLabel.Font.Height = -11
        EditLabel.Font.Name = 'MS Sans Serif'
        EditLabel.Font.Style = []
        EditLabel.ParentFont = False
        LabelPosition = lpAbove
        LabelSpacing = 3
        TabOrder = 1
      end
      object LabeledEdit3: TLabeledEdit
        Left = 16
        Top = 80
        Width = 121
        Height = 21
        EditLabel.Width = 79
        EditLabel.Height = 13
        EditLabel.Caption = #1052#1080#1085#1091#1090#1072', '#1080#1085#1076#1077#1082#1089
        EditLabel.Font.Charset = DEFAULT_CHARSET
        EditLabel.Font.Color = clNavy
        EditLabel.Font.Height = -11
        EditLabel.Font.Name = 'MS Sans Serif'
        EditLabel.Font.Style = []
        EditLabel.ParentFont = False
        LabelPosition = lpAbove
        LabelSpacing = 3
        TabOrder = 2
      end
      object LabeledEdit4: TLabeledEdit
        Left = 152
        Top = 80
        Width = 121
        Height = 21
        EditLabel.Width = 98
        EditLabel.Height = 13
        EditLabel.Caption = #1052#1080#1085#1091#1090#1072', '#1080#1085#1082#1088#1077#1084#1077#1085#1090
        EditLabel.Font.Charset = DEFAULT_CHARSET
        EditLabel.Font.Color = clNavy
        EditLabel.Font.Height = -11
        EditLabel.Font.Name = 'MS Sans Serif'
        EditLabel.Font.Style = []
        EditLabel.ParentFont = False
        LabelPosition = lpAbove
        LabelSpacing = 3
        TabOrder = 3
      end
    end
  end
end
