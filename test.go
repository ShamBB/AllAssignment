


package main

import (
    "io"
    "os"


)


func main() {

 
    fi, err := os.Open("alphabet.txt")
    if err != nil {
        panic(err)
    }
    
    defer func() {
        if err := fi.Close(); err != nil {
            panic(err)
        }
    }()

  
    fo, err := os.Create("bin.bin")
    if err != nil {
        panic(err)
    }
  
    defer func() {
        if err := fo.Close(); err != nil {
            panic(err)
        }
    }()

    
    buf := make([]byte, 4096)
    for {
       
        n, err := fi.Read(buf)
        if err != nil && err != io.EOF {
            panic(err)
        }
        if n == 0 {
            break
        }

      
        if _, err := fo.Write(buf[:n]); err != nil {
            panic(err)
        }
    }


   open, err := os.Open("bin.bin")
    if err != nil {
        panic(err)
    }
    
    defer func() {
        if err := open.Close(); err != nil {
            panic(err)
        }
    }()


    create, err := os.Create("BinarytoString.txt")
    if err != nil {
        panic(err)
    }

    defer func() {
        if err := create.Close(); err != nil {
            panic(err)
        }
    }()

  
    buffer := make([]byte, 4096)
    for {
      
        z, err := open.Read(buffer)
        if err != nil && err != io.EOF {
            panic(err)
        }
        if z == 0 {
            break
        }

       
        if _, err := create.Write(buf[:z]); err != nil {
            panic(err)
        }
    }

  

    

}



	

