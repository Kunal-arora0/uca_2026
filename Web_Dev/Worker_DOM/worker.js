async function getUsers(){
    const response = await fetch("https://dummyjson.com/users");
    const data = await response.json();
    self.postMessage(data);
}

self.onmessage =(event) =>{
    
    console.log(event.data);
    getUsers();
    
   
}