/*
	Çª¸¥¹Ù
*/

#if defined _puni_included
  #endinput
#endif

#define _puni_included
#pragma library dini

#if defined MAX_STRING
#define PUNI_MAX_STRING MAX_STRING
#else
#define PUNI_MAX_STRING 255
#endif

write(File:handle,const string[])
	for(new i=0; i<strlen(string); i++)
		fputchar(handle,string[i],false);

stock puni_Write(filename[], const string[])
{
	new File:handle;
	handle = fopen(filename, io_readwrite);
	write(handle, string);
	write(handle, "\r\n");
	fclose(handle);
}

stock puni_Exists(filename[]) {
	return fexist(filename);
}

stock puni_Remove(filename[]) {
	return fremove(filename);
}

stock puni_Create(filename[]) {
	if (fexist(filename)) return false;
	new File:fhnd;
	fhnd=fopen(filename,io_write);
	if (fhnd) {
		fclose(fhnd);
		return true;
	}
	return false;
}

stock puni_Set(filename[],key[],value[]) {
	// If we have no key, it can't be set
	// we also have no chance to set the value, if all together is bigger then the max string
	new key_length = strlen(key);
	new value_length = strlen(value);
	if (key_length==0 || key_length+value_length+2>PUNI_MAX_STRING) return false;
	
	new File:fohnd, File:fwhnd;
	new tmpres[PUNI_MAX_STRING];
	new bool:wasset=false;
	
	// Let's remove the old *.part file if there was one.
	format(tmpres,sizeof(tmpres),"%s.part",filename);
	fremove(tmpres);
	
	// We'll open the source file.
	fohnd=fopen(filename,io_read);
	if (!fohnd) return false;
	
	fwhnd=fopen(tmpres,io_write);
	if (!fwhnd) {
		// we can't open the second file for writing, so .. let's close the open one and exit.
		fclose(fohnd);
		return false;
	}
	
	while (fread(fohnd,tmpres)) {
		if (
			!wasset
			&& tmpres[key_length]=='='
			&& !strcmp(tmpres, key, true, key_length)	
		) {
				// We've got what needs to be replaced!
				format(tmpres,sizeof(tmpres),"%s=%s",key,value);
				wasset=true;
		} else {
			PUNI_StripNewLine(tmpres);
		}
		write(fwhnd,tmpres);
		write(fwhnd,"\r\n");
	}

	if (!wasset) {
		format(tmpres,sizeof(tmpres),"%s=%s",key,value);
		write(fwhnd,tmpres);
		write(fwhnd,"\r\n");
	}

	fclose(fohnd);
	fclose(fwhnd);

	format(tmpres,sizeof(tmpres),"%s.part",filename);
	if (PUNI_fcopytextfile(tmpres,filename)) {
		return fremove(tmpres);
	}
	return false;
}


stock puni_IntSet(filename[],key[],value) {
   new valuestring[PUNI_MAX_STRING];
   format(valuestring,PUNI_MAX_STRING,"%d",value);
   return puni_Set(filename,key,valuestring);
}

stock puni_Int(filename[],key[]) {
   return strval(puni_Get(filename,key));
}

stock puni_FloatSet(filename[],key[],Float:value) {
   new valuestring[PUNI_MAX_STRING];
   format(valuestring,PUNI_MAX_STRING,"%f",value);
   return puni_Set(filename,key,valuestring);
}

stock Float:puni_Float(filename[],key[]) {
   return floatstr(puni_Get(filename,key));
}

stock puni_Bool(filename[],key[]) {
   return strval(puni_Get(filename,key));
}

stock puni_BoolSet(filename[],key[],value) {
	if (value) {
		return puni_Set(filename,key,"1");
	}
	return puni_Set(filename,key,"0");
}

stock puni_Unset(filename[],key[]) {
	// If we have no key, it can't be set
	// we also have no chance to unset the key, if all together is bigger then the max string
	new key_length = strlen(key);
	if (key_length==0 || key_length+2>PUNI_MAX_STRING) return false;
	
	new File:fohnd, File:fwhnd;
	new tmpres[PUNI_MAX_STRING];
	
	// Let's remove the old *.part file if there was one.
	format(tmpres,PUNI_MAX_STRING,"%s.part",filename);
	fremove(tmpres);
	
	// We'll open the source file.
	fohnd=fopen(filename,io_read);
	if (!fohnd) return false;
	
	fwhnd=fopen(tmpres,io_write);
	if (!fwhnd) {
		// we can't open the second file for writing, so .. let's close the open one and exit.
		fclose(fohnd);
		return false;
	}
	
	while (fread(fohnd,tmpres)) {
		if (
			tmpres[key_length]=='='
			&& !strcmp(tmpres, key, true, key_length)	
		) {
				// We've got what needs to be removed!
		} else {
			PUNI_StripNewLine(tmpres);
			write(fwhnd,tmpres);
			write(fwhnd,"\r\n");
		}
	}
	
	fclose(fohnd);
	fclose(fwhnd);

	format(tmpres,PUNI_MAX_STRING,"%s.part",filename);
	if (PUNI_fcopytextfile(tmpres,filename)) {
		return fremove(tmpres);
	}
	return false;
}

stock puni_Get(filename[],key[]) {
	new tmpres[PUNI_MAX_STRING];
	
	new key_length = strlen(key);
	if (key_length==0 || key_length+2>PUNI_MAX_STRING) return tmpres;
	
	new File:fohnd;
	fohnd=fopen(filename,io_read);
	if (!fohnd) return tmpres;
	
	while (fread(fohnd,tmpres)) {
		if (
			tmpres[key_length]=='='
			&& !strcmp(tmpres, key, true, key_length)	
		) {
			/* We've got what we need */
			PUNI_StripNewLine(tmpres);
			strmid(tmpres, tmpres, key_length + 1, strlen(tmpres), PUNI_MAX_STRING);
			fclose(fohnd);
			return tmpres;
		}
	}
	fclose(fohnd);
	return tmpres;
}


stock puni_Isset(filename[],key[]) {
	new key_length = strlen(key);
	if (key_length==0 || key_length+2>PUNI_MAX_STRING) return false;
	
	new File:fohnd;
	fohnd=fopen(filename,io_read);
	if (!fohnd) return false;
	
	new tmpres[PUNI_MAX_STRING];
	while (fread(fohnd,tmpres)) {
		if (
				tmpres[key_length]=='='
			&&  !strcmp(tmpres, key, true, key_length)	
		) {
			// We've got what we need
			fclose(fohnd);
			return true;
		}
	}
	fclose(fohnd);
	return false;
}



stock PUNI_StripNewLine(string[]) {
	new len = strlen(string);
	if (string[0]==0) return ;
	if ((string[len - 1] == '\n') || (string[len - 1] == '\r')) {
		string[len - 1] = 0;
		if (string[0]==0) return ;
		if ((string[len - 2] == '\n') || (string[len - 2] == '\r')) string[len - 2] = 0;
	}
}

stock PUNI_fcopytextfile(oldname[],newname[]) {
	new File:ohnd,File:nhnd;
	if (!fexist(oldname)) return false;
	ohnd=fopen(oldname,io_read);
	if (!ohnd) return false;
	nhnd=fopen(newname,io_write);
	if (!nhnd) {
		fclose(ohnd);
		return false;
	}
	new tmpres[PUNI_MAX_STRING];
	while (fread(ohnd,tmpres)) {
		PUNI_StripNewLine(tmpres);
		format(tmpres,sizeof(tmpres),"%s\r\n",tmpres);
		write(nhnd,tmpres);
	}
	fclose(ohnd);
	fclose(nhnd);
	return true;
}