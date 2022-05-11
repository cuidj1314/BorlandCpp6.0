object Form1: TForm1
  Left = 201
  Top = 137
  Width = 979
  Height = 601
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 136
    Top = 40
    Width = 48
    Height = 13
    Caption = #21592#24037#21345#21495
  end
  object Label2: TLabel
    Left = 144
    Top = 88
    Width = 24
    Height = 16
    Caption = #22995#21517
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 136
    Top = 136
    Width = 24
    Height = 16
    Caption = #24615#21035
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 128
    Top = 184
    Width = 25
    Height = 17
    Caption = #30005#35805
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object edtC_Id: TEdit
    Left = 216
    Top = 40
    Width = 145
    Height = 21
    TabOrder = 0
    Text = 'edtC_Id'
  end
  object BtnList: TButton
    Left = 40
    Top = 360
    Width = 169
    Height = 57
    Caption = #25968#25454#34920#31034
    TabOrder = 1
    OnClick = BtnListClick
  end
  object BtnNext: TButton
    Left = 344
    Top = 360
    Width = 137
    Height = 57
    Caption = #19979#19968#26465
    TabOrder = 2
    OnClick = BtnNextClick
  end
  object edtC_Name: TEdit
    Left = 216
    Top = 88
    Width = 145
    Height = 21
    TabOrder = 3
    Text = 'edtC_Name'
  end
  object edtC_Sex: TEdit
    Left = 208
    Top = 136
    Width = 113
    Height = 21
    TabOrder = 4
    Text = 'edtC_Sex'
  end
  object edtC_Tel: TEdit
    Left = 208
    Top = 184
    Width = 145
    Height = 21
    TabOrder = 5
    Text = 'edtC_Tel'
  end
  object BtnPrior: TButton
    Left = 216
    Top = 360
    Width = 121
    Height = 57
    Caption = #19978#19968#26465
    TabOrder = 6
    OnClick = BtnPriorClick
  end
  object BtnChange: TButton
    Left = 488
    Top = 360
    Width = 137
    Height = 57
    Caption = #20462#25913#25968#25454
    TabOrder = 7
    OnClick = BtnChangeClick
  end
  object BtnDelete: TButton
    Left = 632
    Top = 360
    Width = 129
    Height = 57
    Caption = #21024#38500#25968#25454
    TabOrder = 8
    OnClick = BtnDeleteClick
  end
  object BtnAdd: TButton
    Left = 768
    Top = 360
    Width = 121
    Height = 57
    Caption = #26032#24314#25968#25454
    TabOrder = 9
    OnClick = BtnAddClick
  end
  object Conn: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=SQLOLEDB.1;Password=123456;Persist Security Info=True;U' +
      'ser ID=sa;Initial Catalog=model'
    Provider = 'SQLOLEDB.1'
    Left = 40
    Top = 8
  end
  object customer: TADODataSet
    Active = True
    Connection = Conn
    CursorType = ctStatic
    CommandText = 'customer'
    CommandType = cmdTable
    Parameters = <>
    Left = 96
    Top = 8
  end
end
