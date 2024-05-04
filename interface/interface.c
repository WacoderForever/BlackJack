

int ask_bet_amount(CliInterface *interface,int balance){
    while (true){
        long value = interface->ask_long(interface,"type the amount of bet");
        if(value > balance){
            interface->warning(interface,"you cannnot bet higher than %d balance\n",balance);
            continue;
        }
        return (int)value;
    }

}
