#include <stdio.h>
#include <string.h>
#include <ctype.h>
struct OnlineShop
{
    char name[1000];
    double rate;
    int quantity;
    char type[100];
};

void Tolower(char s[])
{
    int i;
    for (i = 0; s[i]!='\0'; i++) {
      if(s[i] >= 'A' && s[i] <= 'Z') {
         s[i] = s[i] + 32;
      }
   }
};

void printProducts(struct OnlineShop *os, int size)
{
    int i;
    for(i=0;i<size;i++){
        if(os[i].quantity!=0){
            printf("\n\n\t\t%d->%s,    Quantity:%d,   -BDT:%.2lf",i+1,
               os[i].name,
               os[i].quantity,
               os[i].rate
               );
        }
        else{ continue;}
    }
};



void AddProducts(struct OnlineShop *os,int num)
{
    char nam[1000],type[100];
    double rat;
    int quan;
    printf("\t\tEnter Product name:");
    fflush(stdin);
    gets(nam);
    strcpy(os[23].name,nam);
    printf("\t\tEnter Product quantity:");
    fflush(stdin);
    scanf("%d",&quan);
    os[23].quantity = quan;
    printf("\t\tEnter Product rate:");
    fflush(stdin);
    scanf("%lf",&rat);
    os[23].rate = rat;
    printf("\t\tEnter Product Type:");
    fflush(stdin);
    gets(type);
    strcpy(os[23].type,type);
    printProducts(os,num);
    printf("\n\n\t\tProduct Added Successfully!!!!");
    printf("\n\n\t\tName:-> %s",os[23].name);
    printf("\n\t\tQuantity:-> %d",os[23].quantity);
    printf("\n\t\tRate:-> %.2lf",os[23].rate);
    printf("\n\t\tType:-> %s",os[23].type);
}

void SearchProducts(struct OnlineShop *os, int size, char product[],int type)
{
    int i,count=0;
    char objProduct[100]="";
    for(i=0; i<size; i++)
    {
        Tolower(product);
        strcpy(objProduct,os[i].name);
        Tolower(objProduct);
        if(strcmp(objProduct,product)==0)
        {
            printf("\n\t\t\t%d->[%s]\tQuantity:%d\tPrice:%.2lf BDT",  //print exactly matched string
               i+1,os[i].name,os[i].quantity, os[i].rate );
               count+=1;
               break;
        }
        else if((strncmp(objProduct,product,4)==0 || strncmp(objProduct,product,5)==0 || strncmp(objProduct,product,8)==0 ||
                strncmp(objProduct,product,6)==0 || strncmp(objProduct,product,7)==0 || strncmp(objProduct,product,9)==0) && (type!=3))
        {
            printf("\n\t\t\t%d->[%s]\tQuantity:%d\tPrice:%.2lf BDT",    //print matches with 7 char
                    i+1,os[i].name,os[i].quantity, os[i].rate );
               count+=1;
        }
        else if((strncmp(objProduct,product,9)==0 || strncmp(objProduct,product,10)==0 || strncmp(objProduct,product,11)==0) && (type==3))
        {
            printf("\n\t\t\t%d->[%s]\tQuantity:%d\tPrice:%.2lf BDT",    //print matches with 7 char
                    i+1,os[i].name,os[i].quantity, os[i].rate );
               count+=1;
        }
        else if(i==size-1 && count==0)
        {
            printf("\n\t\tSearch not found");
            break;
        }
        else{ continue;}
    }
};






int main()
{
   char Name[20], Country[20];
    int Mobile_No;
    printf("\t * Please give your personal informations *");
    printf("\n Name\t  :: ");
    scanf(" %[^\n]s", Name);
    printf("Country\t  :: ");
    scanf(" %[^\n]s", Country);
    printf("Mobile No.:: ");
    scanf("%d", &Mobile_No);
    printf("\n Hello %s \n \n \t********** Welcome to our Online Shop ****** \n", Name);
    printf("                 ------------------------------   \n", Name);

    struct OnlineShop b[30] = {
                                    {"Harry porter Bookset(1-7)",   8000.00,7,      "books"},
                                    {"Hamlet",   500.00, 1,      "books"},
                                    {"A Golden Age ",  1000.00,1,      "books"},
                                    {"A gna Karenina",                 1500.00,1,      "books"},
                                    {"Romeo and Juliet",              1200.00,1,      "books"},
                                    {"Merchant of Venice",            1500.00,1,      "books"},
                                    {"The Unfinished Memoirs",         350.00,1,       "books"},
                                    {"A Game of Thrones",             1250.00,1,      "books"},
                                    {"Breaking Dawn",                 1050.00,1,      "books"},
                                    {" Oresteia",                     1200.00,1,      "books"},
                                    {"Misir Ali Omnibus 1",          1000.00,9,      "books"},
                                    {"Misir Ali Omnibus 2",          1500.00,5,      "books"},
                                    {"Himu Series(1-23)",             4105.00,23,     "books"},
                                    {"Flowers of Flame",                500.00,1,      "books"},
                                    {"Paradoxical Sajid 1 & 2",        800.00,2,      "books"},
                                    {"Ma, Ma, Ma ebong Baba",          300.00,1,      "books"},
                                    {"Bela_furabar_age",               250.00,1,      "books"},
                                    {"Be Smart with Muhammad ",        650.00,1,      "books"},
                                    {"Golpoguccho",                    750.00,1,      "books"},
                                    {"Dipu Number Two",                300.00,1,      "books"},
                                    {"Agnibina",                       200.00,1,      "books"},
                                    {"Nazruler Chotogolpo somogro",    650.00,1,      "books"},
                                    {"Padma Nadir Majhi",              300.00,1,      "books"}
                                };
 struct OnlineShop s[30] = {
                                    {"Black Color Leather Formal Shoe For Men", 3300.00, 1, "Apex"},
                                    {"Master Color Leather Party Formal Shoe For Men", 3250.00, 1, "Apex"},
                                    {"Black Color Leather Formal Shoe For Men", 3300.00, 1, "Apex"},
                                    {"Sprint Royal Blue Kniting Sneaker for Men", 2790.00, 1, "Apex"},
                                    {"Fashion for Men Lining Side Zipper Pointed Toe Ankle Boots", 4400.00, 1, "Apex"},
                                    {"Leather Sandal For Men Black colour", 2490.00, 1, "Apex"},
                                    {" Coffee Pu Sandal for Men", 1693.00, 1, "Apex"},
                                    {"Chocolate Color Leather Formal Shoe For Men", 2000.00, 1, "Bata"},
                                    {"Chocolate colour Leather Formal Shoe For Men ", 2500.00, 1, "Bata"},
                                    {"Slip Men Women Outdoor Sports Aqua Water Shoes", 1200.00, 1, "Bata"},
                                    {"Fly Synthetic Two Strap Sandal for Men", 650.00, 1, "Bata"},
                                    {"North Star Synthetic Casual Lifestyle Sneakers - Blue", 650.00, 1, "Bata"},
                                    {"Black Casual Slip-On Shoe For Men", 850.00, 1, "Bata"},
                                    {"Nike_Airmax 2090 Sneakers For Men", 4990.00, 1, "Nike"},
                                    {"Nike Men's Slipper - 310 (Black) For Men", 899.00, 1, "Nike"},
                                    {"PUMA Men's Tazon 6 Fracture FM Cross-Trainer Shoe", 7690.00, 1, "Puma"},
                                    {"PUMA Men's Roma Basic Sneaker(white)", 8200.00, 1, "Puma"},
                                    {"PUMA Men's Super Liga Og Sneaker", 8992.00, 1, "Puma"},
                                    {"PUMA Men's Smash V2 Sneaker", 9500.00, 1, "Puma"},
                                    {"Adidas_Nite_Jogger_3M_Silver Metallic", 5200.00, 1, "Adidas"},
                                    {"New Style Flip Flop Slipper For Men", 900.00, 1, "Adidas"},
                                    {"Adidas Men's Grand Court Sneaker", 5300.00, 1, "Adidas"},
                                    {"Adidas Men's Daily 2.0 Sneaker", 7500.00, 1, "Adidas"},
                                    {"Adidas Men's Alphabounce 3 Running Shoe", 6970.00, 1, "Adidas"},
                                    {"Brown Mixed Leather Chain Boot for Men", 3500.00, 1, "Sky sea"}
                                };


       struct OnlineShop m[30] = {
                                    {"Samsung A60 6GB/128GB",                          24500.00, 1,       "Samsung"},
                                    {"Samsung A80 8GB/128GB",                          49500.00, 1,       "Samsung"},
                                    {"Samsung M31 8GB/128GB",                          27999.00, 1,       "Samsung"},
                                    {"Samsung S10+ 8GB/128GB",                          99900.00, 1,       "Samsung"},
                                    {"Samsung S20 8GB/128GB",                          87203.00, 1,       "Samsung"},

                                    {"Realme 6i 4GB/128GB",                          17000.00, 1,       "Realme"},
                                    {"Realme  6 Pro 8GB/128GB",                          24500.00, 1,       "Realme"},
                                    {"Realme  7 Pro 6GB/128GB",                          27000.00, 1,       "Realme"},
                                    {"Realme  X 8GB/128GB",                          25000.00, 1,       "Realme"},
                                    {"Realme  X 8GB/128GB",                          39000.00, 1,       "Realme"},

                                    {"Redmi K20 6GB/128GB",                          27000.00, 1,       "Xiaomi"},
                                    {"Redmi K20 Pro 8GB/128GB",                          49999.00, 1,       "Xiaomi"},
                                    {"Redmi K30 6GB/128GB",                          22500.00, 1,       "Xiaomi"},
                                    {"Redmi K30 Pro 8GB/128GB",                          45500.00, 1,       "Xiaomi"},
                                    {"Redmi Note9 Pro Max 6GB/128GB",                          24000.00, 1,       "Xiaomi"},

                                    {"iPhone  7 Plus 3GB+128GB",                          59990.00, 1,       "Apple"},
                                    {"iPhone XR 3GB+256GB",                          98000.00, 1,       "Apple"},
                                    {"iPhone XS 4GB+256GB",                          74000.00, 1,       "Apple"},
                                    {"iPhone  X 3GB+256GB",                          96999.00, 1,       "Apple"},
                                    {"iPhone 11 4GB+256GB",                          99999.00, 1,       "Apple"},

                                    {"OnePlus 6 8GB+128GB",                          44990.00, 1,       "OnePlus"},
                                    {"OnePlus 6T 8GB+128GB",                          54500.00, 1,       "OnePlus"},
                                    {"OnePlus 7 8GB+256GB",                          52500.00, 1,       "OnePlus"},
                                    {"OnePlus 7T 8GB+128GB",                          54990.00, 1,       "OnePlus"},
                                    {"OnePlus Nord 8GB+128GB",                          38000.00, 1,       "OnePlus"}
                                };

struct OnlineShop c[30] = {
                                {"Blue colour Cotton Long Sleeve Formal Shirt for Men",             1200.00, 1,       "Zara"},
                                {"Black colour Cotton Long Sleeve Formal Shirt for Men",            1200.00, 1,       "Zara"},
                                {"Mens Polo Shirt Brown with Diamante Print and Front Stripe Sign", 9000.00, 1,       "Gucchi"},
                                {"Men's Sky Blue Cotton Popeline Slim Fit Shirt 307648 4910",      12020.00, 1,       "Gucchi"},
                                {"Gucci Men's Blue Linen Vintage Striped Long Sleeve T-Shirt",      8000.00, 1,       "Gucchi"},
                                {"Cooper Premium Exclusive Comfortable Short Sleeve Shirt for Men",  1220.00, 1,       "Lee"},
                                {"Black Color Funny comfortable T-shirt for Men",                    350.00, 1,       "Lee"},
                                {"Jeans Pant For Men",                                              2290.00, 1,       "Lee"},
                                {"Bule Denim Jeans Pant for Men-Blac For Men",                      2590.00, 1,       "Lee"},
                                {"Lee Knit Denim Pant for Men",                                     2120.00, 1,       "Lee"},
                                {"Light Blue Knit Denim Pant For Man",                              1290.00, 1,       "Lee"},
                                {"LIGHT PINK PANJABI WITH BEST COTTON FABRIC",                     1500.00, 1,        "Blue Jeans"},
                                {"Exclusive Black Stylish  Best Quality Cotton Long Panjaby ",     2190.00, 1,        "Blue Jeans"},
                                {"Black and White Stylish Quality Cotton Panjaby ",                2290.00, 1,        "Blue Jeans"},

                                {"Sarees for Women Banarasi Kanjivaram Art Silk Woven ",           4500.00, 1,        "Elina fashion"},
                                {"Women's Partywear Printed Saree with Unstitched Blouse ",        3990.00, 1,        "Elina fashion"},
                                {"Women Vintage Floral Cocktal Party Dress ",                      1200.00, 1,        "Zanzea"},
                                {"Women Spaghetti Strap Suspender Skirts ",                        1450.00, 1,        "Zanzea"},
                                {"Linen Kameez / Multi-Color Linen Kurti for Women",                900.00, 1,        "Aahil"},
                                {"Champion Women's Classic Jersey Script T-Shirt",                  7000.00,1,        "Gucchi"},
                                {"Black Cotton Printed Half Sleeve T-Shirt for Women  ",            390.00, 1,        "Stone Rose"},
                                {"Ladies T-shirt 4 Quarter ",                                       480.00, 1,        "Blue Jeans"},
                                {"Women's Vintage Patchwork Pockets Puffy Swing Casual Party",     4280.00, 1,        "Blue Jeans"},
                                {"Korean Style Vintage Cozy T-Shirt Loose Decorative Buttons ",    1260.00, 1,        "Scarlett"},
                                {"Women's Striped Leopard Print Camouflage T Shirt ",              1620.00, 1,        "Choopy Sea"}

                            };
struct OnlineShop ca[30] = {
                                {"PHILIPS MMS2160B 2:1 Sound Bar System",                           5190.00, 1,       "Philips"},
                                {"Edifier R1010BT Bookshelf Bluetooth Speaker",                     7200.00, 1,       "Edifier"},
                                {"V810 Cherry MX-Blue Switch USB Mechanical Gaming Keyboard Black", 4000.00, 1,       "Rapoo"},
                                {"WSB01TM 2.4 Ghz Wireless Mouse",                                  1300.00, 1,       "Xiaomi"},
                                {"Razer Mamba HyperFlux + Firefly HyperFlux",                      19000.00, 1,       "Razer"},
                                {"OnePlus E303A Bullets Z Bluetooth Earphone",                     33500.00, 1,       "OnePlus"},
                                {"HP 18000 mAh Power Pack Plus",                                   12000.00, 1,       "HP"},
                                {"Logitech C930c Full HD Webcam",                                  11500.00, 1,       "Logitech"},
                                {"MI Box S MDZ-22-AB Android TV Box (Global Version)",              5590.00, 1,       "Xiaomi"},
                                {"M2TS 2.5'' SSD M.2 TO SATA 3.0 Adapter/Enclosure",                2500.00, 1,       "Orico"}
                            };


    static int totalCost;
    int i, j, choice, cc, a[9], cost[9];
    for (i = 0; i < 9; i++)
        a[i] = 0;
    double total_cost = 0.0, given_amount = 0.0;
    do
    {
        printf("Enter Any option number:\n");
        printf("\t1-> Display Products\n");
        printf("\t2-> Search Products\n");
        printf("\t3-> Buy Products\n");
        printf("\t4-> Change Products\n");
        printf("\t5-> Add Products\n");
        printf("\t6-> Exit\n");
        scanf("%d", &cc);


 if (cc == 1)
        {
            int num = sizeof(b)/sizeof(b[0]);
            printf("\n\n\t\t\t----[All Books In Stock]----");
            printProducts(b,num);

            num = sizeof(s)/sizeof(s[0]);
            printf("\n\n\n\t\t\t----[All Shoes In Stock]----");
            printProducts(s,num);

            num = sizeof(c)/sizeof(c[0]);
            printf("\n\n\n\t\t\t----[All Cloths In Stock]---");
            printProducts(c,num);

            num = sizeof(m)/sizeof(m[0]);
            printf("\n\n\n\t\t\t----[All Mobiles In Stock]---");
            printProducts(m,num);

            num = sizeof(ca)/sizeof(ca[0]);
            printf("\n\n\n\t\t\t----[All Computer Accessories In Stock]---");
            printProducts(ca,num);
        }


else if(cc==2)
               {

                printf("\n\t\t1 - Books\n\t\t2 - Shoes\n\t\t3 - Mobiles \n\t\t4 - Clothes \n\t\t5 - Computer Accessories\n");
                printf("\n\t\tSelect an option to search products ::");
                scanf("%d", &choice);

            switch (choice)
            {
                case 1:
                {
                    int search=1;
                    do{
                        char book[100];
                        int num = sizeof(b)/sizeof(b[0]);
                        printf("\n\t\tEnter the book name:");
                        scanf(" %[^\n]s",book);
                        SearchProducts(b,num,book,choice);
                        printf("\n\n\t\tDo you want to search any other book press 1 or press 0 for exit: ");
                        scanf("%d", &search);
                    }while(search==1);
                    break;
                }
                case 2:
                { int search=1;
                    do{
                        char shoe[100];
                        int num = sizeof(b)/sizeof(b[0]);
                        printf("\n\t\tEnter the Shoe name:");
                        scanf(" %[^\n]s",shoe);
                        SearchProducts(b,num,shoe,choice);
                        printf("\n\n\t\tDo you want to search any other shoe press 1 or press 0 for exit: ");
                        scanf("%d", &search);
                    }while(search==1);
                    break;

                }
                case 3:
                {
                    int search=1;
                    do{
                        char mobile[100];
                        int num = sizeof(m)/sizeof(m[0]);
                        printf("\n\t\tEnter the mobile name:");
                        scanf(" %[^\n]s",mobile);
                        SearchProducts(m,num,mobile,choice);
                        printf("\n\n\t\tDo you want to search any other mobile press 1 or press 0 for exit: ");
                        scanf("%d", &search);
                    }while(search==1);
                    break;
                }
                case 4:
                {int search=1;
                    do{
                        char cloth[100];
                        int num = sizeof(b)/sizeof(b[0]);
                        printf("\n\t\tEnter the cloth name:");
                        scanf(" %[^\n]s",cloth);
                        SearchProducts(b,num,cloth,choice);
                        printf("\n\n\t\tDo you want to search any other cloth press 1 or press 0 for exit: ");
                        scanf("%d", &search);
                    }while(search==1);
                    break;

                }
                case 5:
                {int search=1;
                    do{
                        char computer_accessories[100];
                        int num = sizeof(b)/sizeof(b[0]);
                        printf("\n\t\tEnter the computer accessories name:");
                        scanf(" %[^\n]s",computer_accessories);
                        SearchProducts(b,num,computer_accessories,choice);
                        printf("\n\n\t\tDo you want to search any other computer accessories press 1 or press 0 for exit: ");
                        scanf("%d", &search);
                    }while(search==1);
                    break;

                }

            }
        }




else if (cc == 3)
                  {
                   printf("\n\t\t1 - Books\n\t\t2 - Shoes\n\t\t3 - Mobiles \n\t\t4 - Clothes \n\t\t5 - Computer Accessories");
                   printf("\nSelect an option to display products ::");
                   scanf("%d", &choice);

            switch (choice)
            {
            case 1:
            {
                int anotherBuy = 1;
                do
                {
                    int accessoriesChoice;
                    printf("\n\t\t \t All Books in the inventory\n");
                    for (i = 0; i < 23; i++)
                    {
                        printf("\n%d-:%s,\tBook:%d, -BDT:%.2lf\n", i + 1,
                               b[i].name,
                               b[i].quantity,
                               b[i].rate);
                    }
                    printf("\nEnter the number of the item you wish to buy :: ");
                    scanf("%d", &accessoriesChoice);
                    if (accessoriesChoice >= 1 && accessoriesChoice <= 23)
                    {
                        if (b[accessoriesChoice - 1].quantity > 0)
                            total_cost += b[accessoriesChoice - 1].rate;
                    }
                    //
                    printf("\nDo you want to buy anything else ? Press 1 for buying more products. \n Press 0 to exit.\n ");
                    scanf("%d", &anotherBuy);
                } while (anotherBuy == 1);
                break;
            }
            case 2:
            {
                int anotherBuy = 2;
                do
                {
                    int accessoriesChoice;
                    printf("\t\t\tAll Shoes in the inventory");
                    for (i = 0; i < 25; i++)
                    {
                        printf("\n%d-:%s,  Shoe:%d, -BDT:%.2lf Brand: %s\n", i + 1,
                               s[i].name,
                               s[i].quantity,
                               s[i].rate,
                               s[i].type);
                    }
                    printf("Enter the number of the item you wish to buy : ");
                    scanf("%d", &accessoriesChoice);
                    if (accessoriesChoice >= 2 && accessoriesChoice <= 25)
                    {
                        if (s[accessoriesChoice - 1].quantity > 0)
                            total_cost += s[accessoriesChoice - 1].rate;
                    }

                    printf("\nDo you want to buy anything else ? Press 1 for buying more products.\n Press 0 to exit.\n ");
                    scanf("%d", &anotherBuy);
                } while (anotherBuy == 1);
                break;
            }
            case 3:
            {
                int anotherBuy = 1;
                do
                {
                    int accessoriesChoice;
                    printf("\n\t\t\tAll Mobiles in the inventory\n");
                    for (i = 0; i < 25; i++)
                    {
                        printf("\n%d-:%s,  Mobile:%d, -BDT:%.2lf Brand: %s\n", i + 1,
                               m[i].name,
                               m[i].quantity,
                               m[i].rate,
                               m[i].type);
                    }
                    printf("\nEnter the number of the item you wish to buy :: ");
                    scanf("%d", &accessoriesChoice);
                    if (accessoriesChoice >= 1 && accessoriesChoice <= 25)
                    {
                        if (m[accessoriesChoice - 1].quantity > 0)
                            total_cost += m[accessoriesChoice - 1].rate;
                    }
                    //
                    printf("Do you want to buy anything else ? Press 1 for buying more products. \n Press 0 to exit.\n ");
                    scanf("%d", &anotherBuy);
                } while (anotherBuy == 1);
                break;
            }


                case 4:
            {
                int anotherBuy = 1;
                do
                {
                    int accessoriesChoice;
                    printf("\n\t\t\tAll Clothes in the inventory\n");
                    for (i = 0; i < 25; i++)
                    {
                        printf("\n%d-:%s,  Cloth:%d, -BDT:%.2lf Brand: %s\n", i + 1,
                               c[i].name,
                               c[i].quantity,
                               c[i].rate,
                               c[i].type);
                    }
                    printf("\nEnter the number of the item you wish to buy :: ");
                    scanf("%d", &accessoriesChoice);
                    if (accessoriesChoice >= 1 && accessoriesChoice <= 25)
                    {
                        if (c[accessoriesChoice - 1].quantity > 0)
                            total_cost += c[accessoriesChoice - 1].rate;
                    }

                    printf("Do you want to buy anything else ? Press 1 for buying more products. \n Press 0 to exit.\n ");
                    scanf("%d", &anotherBuy);
                } while (anotherBuy == 1);
                break;
            }


               case 5:
            {
                int anotherBuy = 1;
                do
                {
                    int accessoriesChoice;
                    printf("\n\t\t\tAll Computer Accessories in the inventory\n");
                    for (i = 0; i < 10; i++)
                    {
                        printf("\n%d-:%s,  Computer Accessories:%d, -BDT:%.2lf Brand: %s\n", i + 1,
                               ca[i].name,
                               ca[i].quantity,
                               ca[i].rate,
                               ca[i].type);
                    }
                    printf("\nEnter the number of the item you wish to buy :: ");
                    scanf("%d", &accessoriesChoice);
                    if (accessoriesChoice >= 1 && accessoriesChoice <= 10)
                    {
                        if (ca[accessoriesChoice - 1].quantity > 0)
                            total_cost += ca[accessoriesChoice - 1].rate;
                    }

                    printf("Do you want to buy anything else ? Press 1 for buying more products. \n Press 0 to exit.\n ");
                    scanf("%d", &anotherBuy);
                } while (anotherBuy == 1);
                break;
            }
            }
        }



else if (cc == 4)
                   {
                   printf("\n\t\t1 - Books\n\t\t2 - Shoes\n\t\t3 - Mobiles \n\t\t4 - Clothes \n\t\t5 - Computer Accessories\n");
                   printf("\n\t\tSelect an option to search products ::");
                   scanf("%d", &choice);
            switch (choice)
            {
                case 1:
                {
                    int change=1;
                    do{
                         char data[500];

                        FILE * fPtr;
                        fPtr = fopen("file1.txt", "a+");
                        if(fPtr == NULL)
                        {
                            printf("Unable to create file.\n");
                        }
                        printf("Please give the information that you gave : \n");

                        printf("Name :: ");
                        fflush(stdin);
                        gets(data);
                        fputs(data,fPtr);
                        fclose(fPtr);

                        printf("Country :: ");
                        fflush(stdin);
                        gets(data);
                        fputs(data,fPtr);
                        fclose(fPtr);

                        printf("Mobile No. :: ");
                        fflush(stdin);
                        gets(data);
                        fputs(data,fPtr);
                        fclose(fPtr);

                        printf("\nProducts No.: ");
                        fflush(stdin);
                        gets(data);
                        fputs(data,fPtr);
                        fclose(fPtr);

                        printf("\nProducts Name: ");
                        fflush(stdin);
                        gets(data);
                        fputs(data,fPtr);
                        fclose(fPtr);


                        printf("Your request has successfully received and stored.) \n");
                        printf("\n\n\t\tDo you want to search any other book press 1 or press 0 for exit: ");
                        scanf("%d", &change);
                    }while(change==1);
                    break;
                }
                case 2:
                {
                    int change=1;
                    do{
                         char data[500];

                        FILE * fPtr;
                        fPtr = fopen("file1.txt", "a+");
                        if(fPtr == NULL)
                        {
                            printf("Unable to create file.\n");
                        }

                         printf("Please give the information that you gave : \n");

                        printf("Name :: ");
                        fflush(stdin);
                        gets(data);
                        fputs(data,fPtr);
                        fclose(fPtr);

                        printf("Country :: ");
                        fflush(stdin);
                        gets(data);
                        fputs(data,fPtr);
                        fclose(fPtr);

                        printf("Mobile No. :: ");
                        fflush(stdin);
                        gets(data);
                        fputs(data,fPtr);
                        fclose(fPtr);

                        printf("\nProducts No.: ");
                        fflush(stdin);
                        gets(data);
                        fputs(data,fPtr);
                        fclose(fPtr);

                        printf("\nProducts Name: ");
                        fflush(stdin);
                        gets(data);
                        fputs(data,fPtr);
                        fclose(fPtr);


                        printf("Your request has successfully received and stored.) \n");
                        printf("\n\n\t\tDo you want to search any other book press 1 or press 0 for exit: ");
                        scanf("%d", &change);
                    }while(change==1);
                    break;


                }
                case 3:
                {
                    int change=1;
                    do{
                         char data[500];


                        FILE * fPtr;
                        fPtr = fopen("file1.txt", "a+");

                        if(fPtr == NULL)
                        {
                            printf("Unable to create file.\n");
                        }

                         printf("Please give the information that you gave : \n");

                        printf("Name :: ");
                        fflush(stdin);
                        gets(data);
                        fputs(data,fPtr);
                        fclose(fPtr);

                        printf("Country :: ");
                        fflush(stdin);
                        gets(data);
                        fputs(data,fPtr);
                        fclose(fPtr);

                        printf("Mobile No. :: ");
                        fflush(stdin);
                        gets(data);
                        fputs(data,fPtr);
                        fclose(fPtr);

                        printf("\nProducts No.: ");
                        fflush(stdin);
                        gets(data);
                        fputs(data,fPtr);
                        fclose(fPtr);

                        printf("\nProducts Name: ");
                        fflush(stdin);
                        gets(data);
                        fputs(data,fPtr);
                        fclose(fPtr);


                        printf("Your request has successfully received and stored.) \n");
                        printf("\n\n\t\tDo you want to search any other book press 1 or press 0 for exit: ");
                        scanf("%d", &change);
                    }while(change==1);
                    break;
                }
                case 4:
                {
                    int change=1;
                    do{
                         char data[500];


                        FILE * fPtr;
                        fPtr = fopen("file1.txt", "a+");

                        if(fPtr == NULL)
                        {
                            printf("Unable to create file.\n");
                        }

                         printf("Please give the information that you gave : \n");

                        printf("Name :: ");
                        fflush(stdin);
                        gets(data);
                        fputs(data,fPtr);
                        fclose(fPtr);

                        printf("Country :: ");
                        fflush(stdin);
                        gets(data);
                        fputs(data,fPtr);
                        fclose(fPtr);

                        printf("Mobile No. :: ");
                        fflush(stdin);
                        gets(data);
                        fputs(data,fPtr);
                        fclose(fPtr);

                        printf("\nProducts No.: ");
                        fflush(stdin);
                        gets(data);
                        fputs(data,fPtr);
                        fclose(fPtr);

                        printf("\nProducts Name: ");
                        fflush(stdin);
                        gets(data);
                        fputs(data,fPtr);
                        fclose(fPtr);


                        printf("Your request has successfully received and stored.) \n");
                        printf("\n\n\t\tDo you want to search any other book press 1 or press 0 for exit: ");
                        scanf("%d", &change);
                    }while(change==1);
                    break;

                }
                case 5:
                {
                    int change=1;
                    do{
                         char data[500];


                        FILE * fPtr;
                        fPtr = fopen("file1.txt", "a+");

                        if(fPtr == NULL)
                        {
                            printf("Unable to create file.\n");
                        }

                        printf("Please give the information that you gave : \n");

                        printf("Name :: ");
                        fflush(stdin);
                        gets(data);
                        fputs(data,fPtr);
                        fclose(fPtr);

                        printf("Country :: ");
                        fflush(stdin);
                        gets(data);
                        fputs(data,fPtr);
                        fclose(fPtr);

                        printf("Mobile No. :: ");
                        fflush(stdin);
                        gets(data);
                        fputs(data,fPtr);
                        fclose(fPtr);

                        printf("\nProducts No.: ");
                        fflush(stdin);
                        gets(data);
                        fputs(data,fPtr);
                        fclose(fPtr);

                        printf("\nProducts Name: ");
                        fflush(stdin);
                        gets(data);
                        fputs(data,fPtr);
                        fclose(fPtr);


                        printf("Your request has successfully received and stored.) \n");
                        printf("\n\n\t\tDo you want to search any other book press 1 or press 0 for exit: ");
                        scanf("%d", &change);
                    }while(change==1);
                    break;

                }
            }
        }




 else if(cc==5)
                {
                char uname[20],pass[30];
                printf("You have to login first!!\n\tUsername:");
                scanf("%s",&uname);
                printf("\tPassword:");
                scanf("%s",&pass);

            if((strcmp(uname,"rahi")==0) && (strcmp(pass,"rahi1234")==0))
            {
                printf("\tLogin successful");
                printf("\n\t\t1 - Books\n\t\t2 - Shoes\n\t\t3 - Mobiles \n\t\t4 - Clothes \n\t\t5 - Computer Accessories\n");
                printf("\n\t\tSelect an option to Add products ::");
                scanf("%d", &choice);
                switch (choice)
                {
                    case 1:
                    {
                        int add=1;
                        do
                        {
                            int num = sizeof(b)/sizeof(b[0]);
                            AddProducts(b,num);
                            printf("\n\n\t\tDo you want to add any other Book press 1 or press 0 for exit: ");
                            scanf("%d", &add);
                        }while(add==1);
                        break;

                    }
                    case 2:
                    {
                        int add=1;
                        do
                        {
                            int num = sizeof(s)/sizeof(s[0]);
                            AddProducts(s,num);
                            printf("\n\n\t\tDo you want to add any other Shoe press 1 or press 0 for exit: ");
                            scanf("%d", &add);
                        }while(add==1);
                        break;

                    }
                    case 3:
                    { int add=1;
                        do
                        {
                            int num = sizeof(m)/sizeof(m[0]);
                            AddProducts(m,num);
                            printf("\n\n\t\tDo you want to add any other Mobile press 1 or press 0 for exit: ");
                            scanf("%d", &add);
                        }while(add==1);
                        break;

                    }
                    case 4:
                 {
                        int add=1;
                        do
                        {
                            int num = sizeof(c)/sizeof(c[0]);
                            AddProducts(c,num);
                            printf("\n\n\t\tDo you want to add any other Cloth press 1 or press 0 for exit: ");
                            scanf("%d", &add);
                        }while(add==1);
                        break;

                    }
                    case 5:
                    {
                        int add=1;
                        do
                        {
                            int num = sizeof(ca)/sizeof(ca[0]);
                            AddProducts(ca,num);
                            printf("\n\n\t\tDo you want to add any other Computer Accessories press 1 or press 0 for exit: ");
                            scanf("%d", &add);
                        }
                        while(add==1);
                        break;

            }

}
}
else
            {
                printf("Invalid username/password");
            }
        }
    } while (cc == 1 || cc == 2 || cc == 3 || cc == 4 || cc==5);

    printf("Your Final Cost is %lf\n", total_cost);
    return 0;
}

