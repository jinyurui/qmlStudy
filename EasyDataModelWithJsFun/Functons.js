function cusSort(list){
    for(var i = 0 ; i < list.length -1; i++){
        for(var j = 0; j < list.length -1 - i; j++){
            var first = list[j].count;
            var second = list[j+1].count;
            if(first < second){
                var temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
    return list;
}
