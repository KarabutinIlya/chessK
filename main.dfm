object MainForm: TMainForm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'MyChess'
  ClientHeight = 409
  ClientWidth = 435
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Image: TImage
    Left = 0
    Top = 0
    Width = 435
    Height = 409
    HelpType = htKeyword
    Align = alClient
    AutoSize = True
    OnMouseDown = ImageMouseDown
    ExplicitLeft = 8
    ExplicitTop = 112
    ExplicitWidth = 337
    ExplicitHeight = 289
  end
  object MainMenu1: TMainMenu
    Left = 312
    Top = 16
    object Game1: TMenuItem
      Caption = 'New Game'
      OnClick = Game1Click
    end
  end
  object ImageList: TImageList
    Left = 368
    Top = 16
  end
end
