var srcDataModel = 0;

WorkerScript.onMessage = function(message) {
    if(!srcDataModel){
        srcDataModel = message.srcModel;
    }
    if(srcDataModel){

        WorkerScript.sendMessage({'type': 'cout', 'ret': srcDataModel.count});
        if(message.action === "sort"){
            console.log("sort!!!!!!!!!!!")
            var count = srcDataModel.count;
            console.log(count);
            for(var i = 0; i < count-1; i++){
                for(var j = 0; j < count-1-i; j++){
                    if(srcDataModel.get(j).age > srcDataModel.get(j+1).age){
                        //srcDataModel.move(j, j+1, 1)
                    }
                }
            }
            WorkerScript.sendMessage({'type': 'sort', 'ret': 'ok'});
        }else if(message.action === "add"){
            console.log("add!!!!!!!!!!!!")
            for(i = 0; i < 10; i++){
                srcDataModel.append({ "name": "Polly",
                                     "type": "Parrot",
                                     "age": i%10,
                                     "size": "Small"});
            }
            WorkerScript.sendMessage({'type': 'add', 'ret': 'add 10 ok'});
        }else if(message.action === "clear"){
            console.log("clear!!!!!!!!!!!!")
            srcDataModel.clear();
        }else if(message.action === "move"){
            console.log("move!!!!!!!!!!!!!")
            srcDataModel.move(0, 2, 1);
            //        srcDataModel.insert(srcDataModel.count, { "name": "qe",
            //                             "type": "e",
            //                             "age": 1001,
            //                             "size": "e"})

            WorkerScript.sendMessage({'type': 'move', 'ret': 'ok'});
            /** quetion
            * @key  listModle move by workerThread
            * @desc
            */
            //ASSERT: "!this->isEmpty()" in
        }else if(message.action === "del"){
            console.log("del!!!!!!!!!!!!!")
            srcDataModel.remove(0);
            WorkerScript.sendMessage({'type': 'del', 'ret': 'ok'});
        }else if(message.action === "sync"){
            console.log("sync!!!!!!!!!!!!")
            srcDataModel.sync();
            console.log(srcDataModel.count);
            return;
        }

        console.log("--------------    " + srcDataModel.count);

        if(srcDataModel){
            srcDataModel.sync();
            WorkerScript.sendMessage({'type': 'over', 'ret': 'ok'});
        }else{
            WorkerScript.sendMessage({'type': 'null', 'ret': 'ok'});
        }
    }
}
