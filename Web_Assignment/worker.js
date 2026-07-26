function printUsers(data){
    for(user of data.users){
        console.log(user.firstName + " - Active");
    }
}


self.onmessage  = async function(){
    const response = await fetch("https://dummyjson.com/users");
    const data = await response.json();
    printUsers(data);
    self.postMessage("Work Completed");
}