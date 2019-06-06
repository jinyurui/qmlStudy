
WorkerScript.onMessage = function(message) {
    if(message.srcModel){
        if(message.action === "sort"){
            console.log("sort!!!!!!!!!!!")
            var count = message.srcModel.count;
            console.log(count);
            for(var i = 0; i < count-1; i++){
                for(var j = 0; j < count-1-i; j++){
                    if(message.srcModel.get(j).age > message.srcModel.get(j+1).age){
                        //message.srcModel.move(j, j+1, 1)
                    }
                }
            }
            WorkerScript.sendMessage({'type': 'sort', 'ret': 'ok'});
        }else if(message.action === "add"){
            console.log("add!!!!!!!!!!!!")
            for(i = 0; i < 10; i++){
                message.srcModel.append({ "name": "Polly",
                                     "type": "Parrot",
                                     "age": i%10,
                                     "size": "Small"});
            }
            WorkerScript.sendMessage({'type': 'add', 'ret': 'add 10 ok'});
        }else if(message.action === "clear"){
            console.log("clear!!!!!!!!!!!!")
            message.srcModel.clear();
        }else if(message.action === "move"){
            console.log("move!!!!!!!!!!!!!")
            message.srcModel.move(0, 2, 1);
            //        message.srcModel.insert(message.srcModel.count, { "name": "qe",
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
            message.srcModel.remove(0);
            WorkerScript.sendMessage({'type': 'del', 'ret': 'ok'});
        }else if(message.action === "sync"){
            console.log("sync!!!!!!!!!!!!")
            message.srcModel.sync();
            console.log(message.srcModel.count);
            return;
        }else if(message.action === "delegateMove"){
            console.log("delegateMove!!!!! you should not see this item!!");
            message.srcModel.items.move(0,1,1);
            console.log(message.srcModel.count);
        }

        console.log("--------------    " + message.srcModel.count);

        if(message.srcModel){
            message.srcModel.sync();
            WorkerScript.sendMessage({'type': 'over', 'ret': 'ok'});
        }else{
            WorkerScript.sendMessage({'type': 'null', 'ret': 'ok'});
        }
    }
    else{
        console.log("err!!!!!!!!")
    }
}
