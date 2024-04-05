void factory_menu(void)
{

}


#if AD8307_INSTALLED
//--------------------------------------------------------------------
// Calibrate Submenu functions
//--------------------------------------------------------------------
void calibrate_menu_level2(void)
{
  static int16_t  current_selection;                     // Acompanhe a seleção atual do menu LCD

  uint8_t cal_set;                                       // Determine se CAL_SET0, CAL_SET1 ou CAL_SET2

  if (menu_level == CAL_SET2_MENU) cal_set = 1;	         // CAL_SET2_MENU
  else cal_set = 0;                                      // CAL_SET0_MENU ou CAL_SET1_MENU

  // Estas definem para ajudar na legibilidade do código
  #define CAL_BAD	0                                      // Sinal de entrada de qualidade insuficiente para calibração
  #define CAL_FWD	1                                      // Bom sinal de entrada detectado, direção direta
  #define CAL_REV	2                                      // Bom sinal de entrada detectado, direção reversa (redundante)
  // A variável abaixo pode assumir um dos três valores definidos acima, com base no
  // sinal de "calibração" de entrada detectado
  static uint8_t cal_sig_direction_quality;
  
  // Obtenha o valor atual
  current_selection = R.cal_AD[cal_set].db10m;

  // Seleção modificada pelo codificador. Lembramos a última seleção, mesmo que seja saída e reentrada


  // Determine a direção e o nível da entrada do sinal de calibração
  // Verifique a direção de avanço e o nível suficiente
 // if ( ((adc_ref*(fwd - rev)/4096.0 * 1000/LOGAMP2_SLOPE) > CAL_INP_QUALITY)
  if ( ((1*(volts1 - volts0) * 1000/LOGAMP2_SLOPE) > CAL_INP_QUALITY)
      && (cal_sig_direction_quality != CAL_FWD))
  {
    cal_sig_direction_quality = CAL_FWD;
    flag.menu_lcd_upd = false;                           // Indica que uma atualização do LCD é necessária
  }
  // Verifique a direção reversa e o nível suficiente
  else if ( ((1*(volts1 - volts0) * 1000/LOGAMP1_SLOPE) > CAL_INP_QUALITY)
           && (cal_sig_direction_quality != CAL_REV))
  {
    cal_sig_direction_quality = CAL_REV;
    flag.menu_lcd_upd = false;                           // Indica que uma atualização do LCD é necessária
  }
  // Verifique o nível insuficiente
  else if (  (1*(ABS((volts0 - volts1)) * 1000/LOGAMP2_SLOPE) <= CAL_INP_QUALITY)
           && (cal_sig_direction_quality != CAL_BAD))
  {
    cal_sig_direction_quality = CAL_BAD;
    flag.menu_lcd_upd = false;                           // Indica que uma atualização do LCD é necessária
  }
  
  // Se a atualização do LCD for necessária
  if(!flag.menu_lcd_upd)  
  {
    flag.menu_lcd_upd = true;                            // Realizamos manutenção em LCD

    // Mantenha a seleção do 'encoder' dentro dos limites do tamanho do menu
    int16_t max_value = 530;                             // Valor de calibração mais alto permitido em dBm * 10
    int16_t min_value = -100;                            // Valor de calibração mais baixo permitido em  dBm * 10
    if(current_selection > max_value) current_selection = max_value;
    if(current_selection < min_value) current_selection = min_value;

    // Armazenar o valor atual na nenória em execução
    R.cal_AD[cal_set].db10m = current_selection;

    

    

    
    nex.writeStr("msg.txt","Adjust (dBm)->");
    
    // Formatar e imprimir o valor atual
    int16_t val_sub = current_selection;
    int16_t val = val_sub / 10;
    val_sub = val_sub % 10;
    if (current_selection < 0)
    {
      val*=-1;
      val_sub*=-1;
      sprintf(lcd_buf," -%1u.%01u",val, val_sub);
    }
    else
    {
      sprintf(lcd_buf," %2u.%01u",val, val_sub);
    }
    nex.writeStr("msg2.txt",String(lcd_buf));

 
    
   
  }

  // Enact a seleção salvando na EEPROM
  if (flag.short_push)
  {
   

    // Salvar valor modificado
    // Se for na direção direta, então calibramos para ambos, usando o valor medido para
    // apenas na direção para fwd
    if (cal_sig_direction_quality == CAL_FWD)
    {
      if (menu_level == CAL_SET0_MENU)
      {
        R.cal_AD[0].Fwd = adc_ref * volts0;
        R.cal_AD[0].Rev = R.cal_AD[0].Fwd;
        // Defina o segundo ponto de calibração em 30 dB menos
        R.cal_AD[1].db10m = R.cal_AD[0].db10m - 300;
        R.cal_AD[1].Fwd = R.cal_AD[0].Fwd - LOGAMP1_SLOPE * .001 * 30;
        R.cal_AD[1].Rev = R.cal_AD[0].Fwd - LOGAMP2_SLOPE * .001 * 30;
      }
      else
      {
        R.cal_AD[cal_set].Fwd = adc_ref * volts0;
        R.cal_AD[cal_set].Rev = R.cal_AD[cal_set].Fwd;
      }
      EEPROM_writeAnything(1,R);
      nex.writeStr("msg.txt","Value Stored");
    }
    // Se for inverso, calibramos apenas para a direção reversa
    else if (cal_sig_direction_quality == CAL_REV)
    {
      if (menu_level == CAL_SET0_MENU)
      {
        R.cal_AD[0].Rev = adc_ref * volts1;
        // Defina o segundo ponto de calibração em 30 dB menos
        R.cal_AD[1].Rev = R.cal_AD[0].Rev - LOGAMP2_SLOPE * .001 * 30;
      }
      else
      {
        R.cal_AD[cal_set].Rev = adc_ref * volts1;
      }
      EEPROM_writeAnything(1,R);
      nex.writeStr("msg.txt","Valor Guardado");
    }
    else                                                 // cal_sig_direction_quality == CAL_BAD
    {
      nex.writeStr("msg.txt","Nada alterado");
    }

    Menu_exit_timer = 100;                               // Mostrar no LCD por 1 segundo
    flag.idle_refresh = true;                            // Forçar a reimpressão do protetor de tela ao sair
    flag.config_mode = true;                             // NÃO terminamos, apenas recuamos
    
    flag.menu_lcd_upd = false;                           // Prepare-se para a próxima vez
    
  }
}// fim calibrate menu_level 2 



//--------------------------------------------------------------------
// Calibrate Menu functions
//--------------------------------------------------------------------
void calibrate_menu(void)
{
  static int8_t	current_selection;                       // Acompanhe a seleção atual do menu LCD

  // Seleção modificada pelo 'encoder''. Lembramos a última seleção, mesmo que seja saída e reentrada
  


  
    // Indica o valor atual armazenado no GainPreset atualmente selecionado
    // A indicação do valor “armazenado” muda de acordo com o GainPreset atualmente selecionado.
   		nex.writeStr("msg.txt","Calibrate");		
    
    if (current_selection <= 2)
    {
      int16_t value=0;

      switch (current_selection)
      {
        case 0:
        case 1:
          value = R.cal_AD[0].db10m;
          break;
        case 2:
          value = R.cal_AD[1].db10m;
          break;
      }
      int16_t val_sub = value;
      int16_t val = val_sub / 10;
      val_sub = val_sub % 10;

      //Imprimir valor da referência atualmente indicada
      
      if (value < 0)
      {
        val*=-1;
        val_sub*=-1;
        sprintf(lcd_buf,"-%1u.%01u",val, val_sub);
      }
      else
      {
        sprintf(lcd_buf,"%2u.%01u",val, val_sub);
      }
      nex.writeStr("msg2.txt",String(lcd_buf));
    }
    else
    {
      nex.writeStr("msg2.txt","--");
    
    }
 

  // Enact selection
  if (flag.short_push)
  {
    flag.short_push = false;                             // Limpar status do botão

    switch (current_selection)
    {
      case 0:
        menu_level = CAL_SET0_MENU;
        flag.menu_lcd_upd = false;                       // forçar reimpressão do LCD
        break;
      case 1:
        menu_level = CAL_SET1_MENU;
        flag.menu_lcd_upd = false;                       // forçar reimpressão do LCD
        break;
      case 2:
        menu_level = CAL_SET2_MENU;
        flag.menu_lcd_upd = false;                       // forçar reimpressão do LCD
        break;
      default:
        
        	nex.writeStr("msg1.txt","Feito w. Cal");			
       
        Menu_exit_timer = 100;                           // Mostrar no LCD por 1 segundo
        flag.idle_refresh = true;                        // Forçar a reimpressão do protetor de tela ao sair
        flag.config_mode = true;                         // NÃO terminamos, apenas recuamos
        //flag.mode_change = true;                         // Sinal para limpeza de tela
        menu_level = 0;                                  // Concluímos este nível de menu
        flag.menu_lcd_upd = false;                       // Prepare-se para a próxima vez
        break;
    }
   
  }
}
#else

//-----------------------------------
 if (cal_sig_direction_quality == CAL_FWD)
    {
      if (menu_level == CAL_SET0_MENU)
      {
 R.cal_AD[0].Fwd = adc_ref * volts0;
        R.cal_AD[0].Rev = R.cal_AD[0].Fwd;
        // Defina o segundo ponto de calibração em 30 dB menos
        R.cal_AD[1].db10m = R.cal_AD[0].db10m - 300;
        R.cal_AD[1].Fwd = R.cal_AD[0].Fwd - LOGAMP1_SLOPE * .001 * 30;
        R.cal_AD[1].Rev = R.cal_AD[0].Fwd - LOGAMP2_SLOPE * .001 * 30;
      }
      else
      {
        R.cal_AD[cal_set].Fwd = adc_ref * fwd/4096.0;
        R.cal_AD[cal_set].Rev = R.cal_AD[cal_set].Fwd;
      }
      EEPROM_writeAnything(1,R);
      VirtLCDy.print("Value Stored");
    }
    // Se for inverso, calibramos apenas para a direção reversa
    else if (cal_sig_direction_quality == CAL_REV)
    {
      if (menu_level == CAL_SET0_MENU)
      {
        R.cal_AD[0].Rev = adc_ref * rev/4096.0;
        // Defina o segundo ponto de calibração em 30 dB menos
        R.cal_AD[1].Rev = R.cal_AD[0].Rev - LOGAMP2_SLOPE * .001 * 30;
      }
      else
      {
        R.cal_AD[cal_set].Rev = adc_ref * rev/4096.0;
      }
      EEPROM_writeAnything(1,R);
      
      nex.writeStr("msg.txt","Valor alterado");
    }
    else                                                 // cal_sig_direction_quality == CAL_BAD
    {
      nex.writeStr("msg.txt","Nada alterado");
    }
#endif