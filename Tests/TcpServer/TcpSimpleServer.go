package main
import (
    "fmt"
    "net"
)

func clien_session(client_conn *net.Conn){
    defer client_conn.Close()
    for{
        input := make([]byte, (1024 * 4)) 
        n, err := client_conn.Read(input) 
        if n == 0 || err != nil {
            fmt.Println("Read error:", err)
            break
        }    
    }
}

func main() { 
    listener, err := net.Listen("tcp", ":5555") 
     
    if err != nil {
        fmt.Println(err) 
        return
    } 

    defer listener.Close() 
    fmt.Println("Server is listening...")
    for { 
        conn, err := listener.Accept() 
        fmt.Println("New clonnection accepter!");

        if err != nil { 
            fmt.Println(err) 
            return
        } 
        fmt.Println("Start new client session");

        go clien_session(&conn)
    } 
}