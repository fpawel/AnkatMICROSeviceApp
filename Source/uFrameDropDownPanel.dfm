object FrameDropDownPanel: TFrameDropDownPanel
  Left = 0
  Top = 0
  Width = 443
  Height = 335
  Align = alTop
  Color = clWindow
  ParentColor = False
  TabOrder = 0
  object Panel13: TPanel
    Left = 0
    Top = 15
    Width = 14
    Height = 320
    Align = alLeft
    BevelOuter = bvNone
    Color = clWhite
    TabOrder = 0
  end
  object Panel8: TPanel
    Left = 429
    Top = 15
    Width = 14
    Height = 320
    Align = alRight
    BevelOuter = bvNone
    ParentColor = True
    TabOrder = 1
  end
  object Panel6: TPanel
    Left = 14
    Top = 15
    Width = 415
    Height = 320
    Align = alClient
    BevelOuter = bvNone
    ParentColor = True
    TabOrder = 2
    object Panel1: TPanel
      Left = 0
      Top = 0
      Width = 415
      Height = 25
      Align = alTop
      BevelOuter = bvNone
      ParentColor = True
      TabOrder = 0
      object Panel2: TPanel
        Left = 0
        Top = 0
        Width = 415
        Height = 25
        Cursor = crHandPoint
        Align = alClient
        BevelOuter = bvNone
        Color = cl3DLight
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        OnClick = Label5Click
        object Label5: TLabel
          Left = 28
          Top = 4
          Width = 46
          Height = 16
          Cursor = crHandPoint
          Caption = 'Caption'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          OnClick = Label5Click
        end
        object Image2: TImage
          Left = 5
          Top = 5
          Width = 15
          Height = 15
          Cursor = crHandPoint
          Picture.Data = {
            055449636F6E0000010001001010020000000000B00000001600000028000000
            1000000020000000010001000000000080000000000000000000000000000000
            0000000000000000FFFFFF000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            000000000000000000000000FFFF0000FFFF0000FFFF0000FE7F0000FE7F0000
            FE7F0000FE7F0000E0070000E0070000FE7F0000FE7F0000FE7F0000FE7F0000
            FFFF0000FFFF0000FFFF0000}
          OnClick = Label5Click
        end
        object Image1: TImage
          Left = 5
          Top = 5
          Width = 15
          Height = 15
          Cursor = crHandPoint
          Picture.Data = {
            055449636F6E0000010001001010020000000000B00000001600000028000000
            1000000020000000010001000000000080000000000000000000000000000000
            0000000000000000FFFFFF000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            000000000000000000000000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000
            FFFF0000FFFF0000E0070000E0070000FFFF0000FFFF0000FFFF0000FFFF0000
            FFFF0000FFFF0000FFFF0000}
          OnClick = Label5Click
        end
      end
    end
    object Panel4: TPanel
      Left = 0
      Top = 40
      Width = 415
      Height = 280
      Align = alClient
      BevelInner = bvRaised
      BevelOuter = bvLowered
      ParentColor = True
      TabOrder = 1
    end
    object Panel7: TPanel
      Left = 0
      Top = 25
      Width = 415
      Height = 15
      Align = alTop
      BevelOuter = bvNone
      ParentColor = True
      TabOrder = 2
    end
  end
  object Panel5: TPanel
    Left = 0
    Top = 0
    Width = 443
    Height = 15
    Align = alTop
    BevelOuter = bvNone
    ParentColor = True
    TabOrder = 3
  end
end
