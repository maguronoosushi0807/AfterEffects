var expressionFileName = "";
var expressionText = "";

//Create Window
var mainWindow = new Window('dialog');
var saveButton = this.add('button', [8, 4, 68, 40], "save");
var loadButton = this.add('button', [70, 4, 130, 40], "load");
var copyButton = this.add('button', [132, 4, 192, 40], "copy");
var pasteButton = this.add('button', [194, 4, 254, 40], "paste");


//Save File
saveButton.onClick = function () {
    var comp = app.project.activeItem;
    if (comp != null && comp instanceof CompItem) {
        var selectedLayers = comp.selectedLayers;

        if (selectedLayers.length == 0) {
            alert("レイヤーが選択されていません。");
        } else if (selectedLayers.length == 1) {

            var selectedProperties = selectedLayers[0].selectedProperties;
            if (selectedLayers.length == 0) {
                alert("プロパティが選択されていません。");
            } else if (selectedProperties.length == 1) {
                var prop = selectedProperties[0];
                
                if (!prop.expression) {
                    alert("選択したレイヤーにはエクスプレッションが存在しません。");
                } else {
                    var expressionBuff = prop.expression;
                    var OutputFile;
                    OutputFile = File.saveDialog("ファイルを保存", "*.aexp");
                    OutputFile.open("w");
                    OutputFile.encoding = "UTF-8";
                    OutputFile.write(expressionBuff);
                    OutputFile.close();
                }

            } else {
                alert("プロパティを1つだけ選択してください。");
            }

        } else {
            alert("レイヤーを1つだけ選択してください。");
        }

    } else {
        alert("コンポジションが選択されていません。");
    }
}

//Load File
loadButton.onClick = function () {
    var fObj = File.openDialog("エクスプレッションファイルを選択", "*.aexp", false);
    if (fObj != null) {
        var res = fObj.open('r');
        expressionFileName = "/*--------" + fObj.name + "--------*/\n";
        if (res) {
            expressionText = fObj.read();
        }
    }


    //paste
    app.beginUndoGroup("ExpressionPaster");
    var comp = app.project.activeItem;
    if (comp != null && comp instanceof CompItem) {
        var selectedLayers = comp.selectedLayers;

        if (selectedLayers.length > 0) {
            for (var j = 0; j < selectedLayers.length; j++) {
                var selectedProperties = selectedLayers[j].selectedProperties;
                if (selectedProperties.length > 0) {
                    for (var i = 0; i < selectedProperties.length; i++) {
                        var prop = selectedProperties[i];

                        var expressionBuff = "";
                        expressionBuff = prop.expression;
                        if (!expressionBuff) {

                        } else {
                            prop.expression = expressionBuff + "\n\n\n";
                        }
                        prop.expression = prop.expression + expressionFileName + expressionText
                    }
                }
            }


        }
    }
    app.endUndoGroup();


}

//Copy Expression
copyButton.onClick = function () {
    var comp = app.project.activeItem;
    if (comp != null && comp instanceof CompItem) {
        var selectedLayers = comp.selectedLayers;

        if (selectedLayers.length == 0) {
            alert("レイヤーが選択されていません。");
        } else if (selectedLayers.length == 1) {
            var selectedProperties = selectedLayers[0].selectedProperties;

            if (selectedProperties.length == 0) {
                alert("プロパティが選択されていません。");
            } else if (selectedProperties.length == 1) {
                var prop = selectedProperties[0];

                if (!prop.expression) {
                    alert("選択したレイヤーにはエクスプレッションが存在しません。");
                } else {
                    expressionFileName = "";
                    expressionText = prop.expression;
                }
            } else {
                alert("プロパティを1つだけ選択してください。");
            }

        } else {
            alert("レイヤーを1つだけ選択してください。");
        }
    } else {
        alert("コンポジションが選択されていません。");
    }
    
}

//Paste File
pasteButton.onClick = function () {
    app.beginUndoGroup("ExpressionPaster");

    var comp = app.project.activeItem;
    if (comp != null && comp instanceof CompItem) {
        var selectedLayers = comp.selectedLayers;

        if (selectedLayers.length > 0) {
            //alert(selectedLayers.length);
            for (var j = 0; j < selectedLayers.length; j++) {
                var selectedProperties = selectedLayers[j].selectedProperties;
                if (selectedProperties.length > 0) {
                    for (var i = 0; i < selectedProperties.length; i++) {
                        var prop = selectedProperties[i];

                        var expressionBuff = "";
                        expressionBuff = prop.expression;
                        if (!expressionBuff) {

                        } else {
                            prop.expression = expressionBuff + "\n\n\n";
                        }
                        prop.expression = prop.expression + expressionFileName + expressionText
                    }
                } else {
                    alert("プロパティが選択されていません。");
                }

            }
        } else {
            alert("レイヤーが選択されていません。");
        }

    } else {
        alert("コンポジションが選択されていません。");
    }
    app.endUndoGroup();


}