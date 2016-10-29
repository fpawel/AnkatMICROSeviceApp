object FrameGraph: TFrameGraph
  Left = 0
  Top = 0
  Width = 829
  Height = 674
  TabOrder = 0
  OnMouseWheelDown = FrameMouseWheelDown
  OnMouseWheelUp = FrameMouseWheelUp
  object Splitter1: TSplitter
    Left = 289
    Top = 0
    Width = 3
    Height = 674
    Cursor = crHSplit
    Color = clBtnFace
    ParentColor = False
  end
  object ScrollBox1: TScrollBox
    Left = 0
    Top = 0
    Width = 289
    Height = 674
    Align = alLeft
    BevelInner = bvNone
    BevelOuter = bvNone
    BorderStyle = bsNone
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    TabOrder = 0
    object Label7: TLabel
      Left = 8
      Top = 8
      Width = 30
      Height = 16
      Caption = #1052#1080#1085'.'
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clNavy
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object grpBxY: TPanel
      Left = 0
      Top = 105
      Width = 289
      Height = 75
      Align = alTop
      BevelOuter = bvNone
      Color = clWindow
      TabOrder = 0
      DesignSize = (
        289
        75)
      object Label5: TLabel
        Left = 8
        Top = 8
        Width = 30
        Height = 16
        Caption = #1052#1080#1085'.'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clNavy
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label6: TLabel
        Left = 8
        Top = 40
        Width = 36
        Height = 16
        Caption = #1052#1072#1082#1089'.'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clNavy
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object edYMin: TEdit
        Left = 48
        Top = 6
        Width = 169
        Height = 24
        Anchors = [akLeft, akTop, akRight]
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        OnChange = edYMinChange
      end
      object cbAutoYMin: TCheckBox
        Left = 224
        Top = 10
        Width = 55
        Height = 17
        Anchors = [akTop, akRight]
        Caption = #1040#1074#1090#1086
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clNavy
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = cbAutoYMinClick
      end
      object edYMax: TEdit
        Left = 48
        Top = 38
        Width = 169
        Height = 24
        Anchors = [akLeft, akTop, akRight]
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        OnChange = edYMaxChange
      end
      object cbAutoYMax: TCheckBox
        Left = 224
        Top = 42
        Width = 55
        Height = 17
        Anchors = [akTop, akRight]
        Caption = #1040#1074#1090#1086
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clNavy
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        OnClick = cbAutoYMaxClick
      end
    end
    object grpBxX: TPanel
      Left = 0
      Top = 0
      Width = 289
      Height = 105
      Align = alTop
      BevelOuter = bvNone
      Color = clWindow
      TabOrder = 1
      DesignSize = (
        289
        105)
      object Label2: TLabel
        Left = 8
        Top = 8
        Width = 30
        Height = 16
        Caption = #1052#1080#1085'.'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clNavy
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label3: TLabel
        Left = 8
        Top = 40
        Width = 36
        Height = 16
        Caption = #1052#1072#1082#1089'.'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clNavy
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object edXMin: TEdit
        Left = 48
        Top = 6
        Width = 169
        Height = 24
        Anchors = [akLeft, akTop, akRight]
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 0
        OnKeyDown = edXMinKeyDown
      end
      object cbAutoXMin: TCheckBox
        Left = 224
        Top = 10
        Width = 55
        Height = 17
        Anchors = [akTop, akRight]
        Caption = #1040#1074#1090#1086
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clNavy
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = cbAutoXMinClick
      end
      object edXMax: TEdit
        Left = 48
        Top = 38
        Width = 169
        Height = 24
        Anchors = [akLeft, akTop, akRight]
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 2
        OnKeyDown = edXMinKeyDown
      end
      object cbAutoXMax: TCheckBox
        Left = 224
        Top = 42
        Width = 55
        Height = 17
        Anchors = [akTop, akRight]
        Caption = #1040#1074#1090#1086
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clNavy
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        OnClick = cbAutoXMaxClick
      end
      object Button1: TButton
        Left = 8
        Top = 76
        Width = 20
        Height = 20
        Caption = '-'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 4
        OnClick = Button1Click
      end
      object Button2: TButton
        Left = 32
        Top = 76
        Width = 20
        Height = 20
        Caption = '<'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 5
        OnClick = Button2Click
      end
      object Button3: TButton
        Left = 56
        Top = 76
        Width = 20
        Height = 20
        Caption = '<<'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 6
        OnClick = Button3Click
      end
      object Button5: TButton
        Left = 80
        Top = 76
        Width = 20
        Height = 20
        Caption = '>>'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 7
        OnClick = Button5Click
      end
      object Button6: TButton
        Left = 104
        Top = 76
        Width = 20
        Height = 20
        Caption = '>'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 8
        OnClick = Button6Click
      end
      object Button7: TButton
        Left = 128
        Top = 76
        Width = 20
        Height = 20
        Caption = '+'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 9
        OnClick = Button7Click
      end
      object Button4: TButton
        Left = 152
        Top = 76
        Width = 67
        Height = 20
        Caption = #1057#1095#1080#1090#1072#1090#1100
        TabOrder = 10
      end
    end
    object grpBxYRight: TPanel
      Left = 0
      Top = 180
      Width = 289
      Height = 75
      Align = alTop
      BevelOuter = bvNone
      Color = clWindow
      TabOrder = 2
      DesignSize = (
        289
        75)
      object Label1: TLabel
        Left = 8
        Top = 8
        Width = 30
        Height = 16
        Caption = #1052#1080#1085'.'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clNavy
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label4: TLabel
        Left = 8
        Top = 40
        Width = 36
        Height = 16
        Caption = #1052#1072#1082#1089'.'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clNavy
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object edYMinRight: TEdit
        Left = 48
        Top = 6
        Width = 169
        Height = 24
        Anchors = [akLeft, akTop, akRight]
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        OnChange = edYMinRightChange
      end
      object cbAutoYMinRight: TCheckBox
        Left = 224
        Top = 10
        Width = 55
        Height = 17
        Anchors = [akTop, akRight]
        Caption = #1040#1074#1090#1086
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clNavy
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = cbAutoYMinRightClick
      end
      object edYMaxRight: TEdit
        Left = 48
        Top = 38
        Width = 169
        Height = 24
        Anchors = [akLeft, akTop, akRight]
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        OnChange = edYMaxRightChange
      end
      object cbAutoYMaxRight: TCheckBox
        Left = 224
        Top = 42
        Width = 55
        Height = 17
        Anchors = [akTop, akRight]
        Caption = #1040#1074#1090#1086
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clNavy
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        OnClick = cbAutoYMaxRightClick
      end
    end
  end
  object chrt_: TChart
    Left = 292
    Top = 0
    Width = 537
    Height = 674
    Cursor = crArrow
    BackWall.Brush.Color = clWhite
    BackWall.Color = clWhite
    BackWall.Pen.Width = 0
    BackWall.Pen.Visible = False
    Gradient.EndColor = 10526880
    Legend.Alignment = laBottom
    Legend.ColorWidth = 50
    Legend.DividingLines.Color = 8388863
    Legend.Font.Height = -13
    Legend.Font.Style = [fsBold]
    Legend.LegendStyle = lsSeries
    Legend.Shadow.Color = clWhite
    Legend.Shadow.HorizSize = 0
    Legend.Shadow.VertSize = 0
    Legend.Symbol.Width = 50
    Legend.TopPos = 0
    MarginBottom = 0
    MarginLeft = 0
    MarginRight = 0
    MarginTop = 0
    Title.AdjustFrame = False
    Title.Alignment = taLeftJustify
    Title.Font.Color = clNavy
    Title.Font.Height = -13
    Title.Font.Style = [fsBold, fsUnderline]
    Title.Text.Strings = (
      'TChart')
    Title.Visible = False
    BottomAxis.Axis.Width = 0
    BottomAxis.DateTimeFormat = 'h:n:s'
    BottomAxis.LabelsSeparation = 20
    Frame.Width = 0
    Frame.Visible = False
    LeftAxis.Axis.Width = 0
    LeftAxis.AxisValuesFormat = '#0.#######'
    LeftAxis.ExactDateTime = False
    LeftAxis.Increment = 1E-5
    LeftAxis.Title.Font.Height = -13
    LeftAxis.Title.Font.Style = [fsBold]
    View3D = False
    Zoom.Pen.Color = clBlack
    Zoom.Pen.Width = 2
    OnAddSeries = chrt_AddSeries
    OnAfterDraw = chrt_AfterDraw
    Align = alClient
    BevelOuter = bvNone
    Color = clWhite
    DockSite = True
    TabOrder = 1
    OnMouseDown = chrt_MouseDown
    OnMouseMove = chrt_MouseMove
    OnMouseUp = chrt_MouseUp
    object panelGraphView: TPanel
      Left = 32
      Top = 32
      Width = 265
      Height = 177
      BevelOuter = bvNone
      Color = clWindow
      TabOrder = 0
      object cbAutoLimitY: TCheckBox
        Left = 8
        Top = 8
        Width = 240
        Height = 17
        Caption = #1040#1074#1090#1086#1084#1072#1090#1080#1095#1077#1089#1082#1072#1103' '#1088#1072#1079#1074#1105#1088#1090#1082#1072
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clNavy
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        OnClick = cbAutoLimitYClick
      end
      object cbNoZoom: TCheckBox
        Left = 8
        Top = 31
        Width = 240
        Height = 17
        Caption = #1048#1089#1093#1086#1076#1085#1099#1081' '#1088#1072#1079#1084#1077#1088
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clNavy
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = cbNoZoomClick
      end
      object cbShowPoints: TCheckBox
        Left = 8
        Top = 56
        Width = 240
        Height = 17
        Caption = #1058#1086#1095#1082#1080
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clNavy
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        OnClick = cbShowPointsClick
      end
      object cbCrossHair: TCheckBox
        Left = 8
        Top = 79
        Width = 240
        Height = 17
        Caption = #1050#1091#1088#1089#1086#1088
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clNavy
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        OnClick = cbCrossHairClick
      end
      object cbShowLegend: TCheckBox
        Left = 8
        Top = 103
        Width = 240
        Height = 17
        Caption = #1047#1072#1075#1086#1083#1086#1074#1082#1080
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clNavy
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 4
        OnClick = cbShowLegendClick
      end
    end
    object clbSeriesList: TCheckListBox
      Left = 32
      Top = 328
      Width = 121
      Height = 200
      OnClickCheck = clbSeriesListClickCheck
      BorderStyle = bsNone
      Columns = 1
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Arial'
      Font.Style = []
      IntegralHeight = True
      ItemHeight = 25
      ParentFont = False
      PopupMenu = popupMenuGraph
      Style = lbOwnerDrawFixed
      TabOrder = 1
      OnDrawItem = clbSeriesListDrawItem
    end
  end
  object popupMenuGraph: TPopupMenu
    OnPopup = popupMenuGraphPopup
    Left = 96
    Top = 424
    object menuSeries: TMenuItem
      Caption = #1043#1088#1072#1092#1080#1082
      object N1: TMenuItem
        Caption = #1048#1079#1084#1077#1085#1080#1090#1100' '#1094#1074#1077#1090' '#1083#1080#1085#1080#1080'...'
        OnClick = N1Click
      end
      object N2: TMenuItem
        Caption = #1048#1079#1084#1077#1085#1080#1090#1100' '#1090#1086#1083#1097#1080#1085#1091' '#1083#1080#1085#1080#1080'...'
        OnClick = N2Click
      end
      object N6: TMenuItem
        Caption = '-'
      end
      object N8: TMenuItem
        Caption = #1054#1095#1080#1089#1090#1080#1090#1100
        OnClick = N8Click
      end
      object N9: TMenuItem
        Caption = #1059#1076#1072#1083#1080#1090#1100' '#1074#1080#1076#1080#1084#1099#1077' '#1090#1086#1095#1082#1080
        OnClick = N9Click
      end
      object N5: TMenuItem
        Caption = '-'
      end
      object menuVertAxis: TMenuItem
        Caption = #1056#1072#1079#1084#1077#1089#1090#1080#1090#1100' '#1089#1083#1077#1074#1072
        OnClick = menuVertAxisClick
      end
    end
  end
  object ColorDialog1: TColorDialog
    Ctl3D = True
    Left = 136
    Top = 424
  end
  object OpenDialog1: TOpenDialog
    DefaultExt = 'ivg'
    Filter = #1043#1088#1072#1092#1080#1082#1080'|*.ivg'
    Left = 16
    Top = 424
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = 'ivg'
    Filter = #1043#1088#1072#1092#1080#1082#1080'|*.ivg|'#1057#1087#1080#1089#1086#1082' '#1079#1085#1072#1095#1077#1085#1080#1081'|*.txt'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofEnableSizing]
    Left = 56
    Top = 424
  end
  object PopupMenu2: TPopupMenu
    Left = 88
    Top = 464
    object N7: TMenuItem
      Caption = #1054#1095#1080#1089#1090#1080#1090#1100
      OnClick = N7Click
    end
    object MenuItem5: TMenuItem
      Caption = #1059#1076#1072#1083#1080#1090#1100' '#1074#1080#1076#1080#1084#1099#1077' '#1090#1086#1095#1082#1080
      OnClick = MenuItem5Click
    end
    object MenuItem7: TMenuItem
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072'...'
      OnClick = MenuItem7Click
    end
    object N4: TMenuItem
      Caption = '-'
    end
    object N3: TMenuItem
      Caption = #1053#1086#1088#1084#1072#1083#1080#1079#1086#1074#1072#1090#1100' '#1075#1088#1072#1092#1080#1082
      OnClick = N3Click
    end
    object X1: TMenuItem
      Caption = #1053#1086#1088#1084#1072#1083#1080#1079#1086#1074#1072#1090#1100' '#1086#1089#1100' X'
      OnClick = X1Click
    end
    object Y1: TMenuItem
      Caption = #1053#1086#1088#1084#1072#1083#1080#1079#1086#1074#1072#1090#1100' '#1086#1089#1100' Y'
      OnClick = Y1Click
    end
  end
end
