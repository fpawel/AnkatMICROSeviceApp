object FrmWait: TFrmWait
  Left = 252
  Top = 310
  BorderStyle = bsNone
  Caption = 'FrmWait'
  ClientHeight = 55
  ClientWidth = 652
  Color = 15855093
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -10
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poScreenCenter
  OnActivate = FormActivate
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object pb1: TProgressBar
    Left = 0
    Top = 43
    Width = 652
    Height = 12
    Align = alBottom
    Min = 0
    Max = 100
    Position = 50
    TabOrder = 0
    Visible = False
  end
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 560
    Height = 43
    Align = alClient
    BevelOuter = bvNone
    Caption = #1055#1086#1078#1072#1083#1091#1081#1089#1090#1072', '#1087#1086#1076#1086#1078#1076#1080#1090#1077'...'
    Color = 15855093
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clMaroon
    Font.Height = -25
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    object Label2: TLabel
      Left = 8
      Top = 1
      Width = 42
      Height = 13
      Alignment = taCenter
      Caption = '00:00:00'
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      OnClick = Label1Click
    end
  end
  object Panel1: TPanel
    Left = 560
    Top = 0
    Width = 92
    Height = 43
    Align = alRight
    BevelOuter = bvNone
    Color = 15855093
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clMaroon
    Font.Height = -25
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    object Label1: TLabel
      Left = 8
      Top = 16
      Width = 39
      Height = 13
      Caption = #1054#1090#1084#1077#1085#1072
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      OnClick = Label1Click
    end
    object imgClose: TImage
      Left = 56
      Top = 7
      Width = 28
      Height = 28
      Picture.Data = {
        055449636F6E0000010002001010100000000400280100002600000020201000
        00000400E80200004E0100002800000010000000200000000100040000000000
        C000000000000000000000001000000000000000000000000000800000800000
        00808000800000008000800080800000C0C0C000808080000000FF0000FF0000
        00FFFF00FF000000FF00FF00FFFF0000FFFFFF00000000000000000000000000
        0000090000090000000000000099900000009000009990000009000000099900
        0099000000009990099000000000099999000000000000999000000000000999
        9900000000009990090000000099990000990000099990000009900009900000
        0000990000000000000000000000000000000000FFFFFFFFFFFBFFFFEFFFFFFF
        C7F7FFFFC7EFFFFFE3CFFFFFF19FFFFFF83FFFFFFC7FFFFFF83FFFFFF1BFFFFF
        C3CFFFFF87E7FFFF9FF3FFFFFFFFFFFFFFFFFFFF280000002000000040000000
        0100040000000000800200000000000000000000100000000000000000000000
        000080000080000000808000800000008000800080800000C0C0C00080808000
        0000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF0000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000990000000000000009000000000000099
        9900000000000000900000000000009999000000000000090000000000000009
        9990000000000099000000000000000099990000000009900000000000000000
        0999900000009900000000000000000000999900000999000000000000000000
        0009999000999000000000000000000000009999099900000000000000000000
        0000099999900000000000000000000000000099990000000000000000000000
        0000099999000000000000000000000000009999099000000000000000000000
        0099999000990000000000000000000009999900000990000000000000000009
        9999900000009900000000000000009999990000000009900000000000000099
        9990000000000009000000000000000999000000000000009000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        00000000000000000000000000000000000000000000000000000000FFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE7FFF7FFC3FFF7F
        FC3FFEFFFE1FFCFFFF0FF9FFFF87F3FFFFC3E3FFFFE1C7FFFFF08FFFFFF81FFF
        FFFC3FFFFFF83FFFFFF09FFFFFC1CFFFFF83E7FFFE07F3FFFC0FF9FFFC1FFEFF
        FE3FFF7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
      OnClick = imgCloseClick
    end
    object btnClose: TSpeedButton
      Tag = 2
      Left = 56
      Top = 7
      Width = 28
      Height = 28
      Hint = #1062#1080#1082#1083#1080#1095#1077#1089#1082#1080#1077' '#1080#1079#1084#1077#1088#1077#1085#1080#1103
      Flat = True
      ParentShowHint = False
      ShowHint = True
      OnClick = btnCloseClick
    end
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 480
    Top = 8
  end
end
