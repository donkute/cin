import socket

loop = True
while True:
    print("Enter \n 1.Resolve URL to IP\n 2. To resolve IP to URL.")
    choice = input().strip()

    try:
        if choice == '1':
            url = input("Enter URL: ").strip()
            ip_address = socket.gethostbyname(url)
            print("IP Address",ip_address)
        elif choice == '2':
            ip = input("Enter IP: ").strip()
            url = socket.gethostbyaddr(ip)[0]
            print("URL IS: ",url)
        else:
            print("Invalid Choice")
    except socket.gaierror as e:
        print("Not Found", e)
