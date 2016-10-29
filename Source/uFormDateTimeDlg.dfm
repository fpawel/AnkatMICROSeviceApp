object FormDateTimeDlg: TFormDateTimeDlg
  Left = 437
  Top = 280
  BorderStyle = bsNone
  Caption = 'FormUserDtTmDlg'
  ClientHeight = 267
  ClientWidth = 417
  Color = clWindow
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clNavy
  Font.Height = -16
  Font.Name = 'Arial'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 18
  object Panel4: TPanel
    Left = 8
    Top = 8
    Width = 401
    Height = 249
    BevelInner = bvRaised
    BevelOuter = bvLowered
    ParentColor = True
    TabOrder = 0
    object Label1: TLabel
      Left = 8
      Top = 8
      Width = 161
      Height = 18
      Caption = #1042#1074#1077#1076#1080#1090#1077' '#1076#1072#1090#1091' '#1080' '#1074#1088#1077#1084#1103
    end
    object Button1: TButton
      Left = 272
      Top = 40
      Width = 105
      Height = 35
      Caption = #1055#1088#1080#1084#1077#1085#1080#1090#1100
      ModalResult = 1
      TabOrder = 2
    end
    object Button2: TButton
      Left = 272
      Top = 88
      Width = 105
      Height = 35
      Caption = #1054#1090#1084#1077#1085#1072
      ModalResult = 2
      TabOrder = 3
    end
    object GroupBox1: TGroupBox
      Left = 8
      Top = 32
      Width = 233
      Height = 97
      Caption = #1086#1090
      TabOrder = 0
      object DateTimePicker5: TDateTimePicker
        Left = 8
        Top = 32
        Width = 217
        Height = 25
        CalAlignment = dtaLeft
        Date = 40826.4177985648
        Format = 'dd MMMM yyyy'
        Time = 40826.4177985648
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkDate
        ParseInput = False
        TabOrder = 0
      end
      object DateTimePicker1: TDateTimePicker
        Left = 8
        Top = 64
        Width = 217
        Height = 25
        CalAlignment = dtaLeft
        Date = 40826.4177985648
        Format = 'HH:mm'
        Time = 40826.4177985648
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkTime
        ParseInput = False
        TabOrder = 1
      end
    end
    object GroupBox2: TGroupBox
      Left = 8
      Top = 136
      Width = 233
      Height = 97
      Caption = #1076#1086
      TabOrder = 1
      object DateTimePicker2: TDateTimePicker
        Left = 8
        Top = 32
        Width = 217
        Height = 25
        CalAlignment = dtaLeft
        Date = 40826.4177985648
        Format = 'dd MMMM yyyy'
        Time = 40826.4177985648
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkDate
        ParseInput = False
        TabOrder = 0
      end
      object DateTimePicker3: TDateTimePicker
        Left = 8
        Top = 64
        Width = 217
        Height = 25
        CalAlignment = dtaLeft
        Date = 40826.4177985648
        Format = 'HH:mm'
        Time = 40826.4177985648
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkTime
        ParseInput = False
        TabOrder = 1
      end
    end
  end
end
