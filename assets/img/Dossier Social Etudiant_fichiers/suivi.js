function ValideIdentif() {
	if (document.form1.NumeroINE.value == "") {
		alert("Vous devez saisir votre numéro INE.");
		document.form1.NumeroINE.focus();
		return false;
	}
	if (document.form1.NumeroINE.value.length != 11) {
		alert ("Le numéro INE que vous avez saisi est incomplet (11 positions obligatoires).");
		document.form1.NumeroINE.focus();
		return false;
	}
	if (document.form1.NomCourt.value == "") {
		alert("Vous devez saisir votre nom (10 premiers caractères).");
		document.form1.NomCourt.focus();
		return false;
	}
	
	/* CZ - Début modification suite Evolution_003 */
	if (document.form1.DateDeNaissance.value == "") {
		alert("Vous devez saisir votre date de naissance.");
		return false;
	}
	/* CZ - Fin modification suite Evolution_003 */
	
	return true;
}


function openWin(url, nom){
	var MinWin, winOpts="width=800,height=800,resizable=yes,scrollbars=yes,location=no";
	MinWin = window.open(url, nom, winOpts);
//	if(navigator.appVersion.indexOf("(X11") != -1 || navigator.appVersion.indexOf("(Mac") != -1) MinWin = window.open(url, nom, winOpts);
}

function notif(path, rang){
	lanotif = openWin(path+"/notif?rqRang="+rang,"Notification");
//	lanotif.document.title = 'Notification';
}

/* Début Commande_20_2016 :  ARPE - ajout de pièces complémentaires */
function notifARPE(path, rang){
	lanotif = openWin(path+"/notifArpe?rqRang="+rang,"Notification ARPE");
}
/* Fin Commande_20_2016 :  ARPE - ajout de pièces complémentaires */

function ValidePwd(){
	if (document.PasswdForm.motDePasse.value == "") {
		alert("Veuillez saisir votre mot de passe.");
		document.PasswdForm.motDePasse.focus();
		return false;
	}
	if (document.PasswdForm.motDePasse.value != document.PasswdForm.confirmation.value){
		alert("La saisie du mot de passe est incorrecte.");
		document.PasswdForm.motDePasse.focus();
		return false;
	}
	return true;
}

//********************************************
// FONCTION twValide_courriel()
// ********************************************
function twValide_courriel(nChamp) {
  // Ajouter ce code dans la saisie du champs
  //  onBlur="twValide_courriel(this)"
  if (nChamp.value.length > 0) {
    if ((nChamp.value.lastIndexOf(".") < nChamp.value.indexOf("@")+3 
      || nChamp.value.lastIndexOf(".") > nChamp.value.length-3 
      || nChamp.value.indexOf("@") < 1 ) 
      || nChamp.value.indexOf("@") != nChamp.value.lastIndexOf("@")) {
      alert("\nSaisie invalide!\n\nAssurez-vous d'entrer un format valide de courriel.");

      nChamp.focus();
      nChamp.select();
    }
  }
}
/* Début Commande_06_2016 : Confirmation par code de l'IBAN dans le suivi */
function afficherSaisieCode(){
	// affichage du champ de saisie du code 
	/* Début Commande_08_2016 : Masquage de l'IBAN */
	if(document.getElementById("divSaisieJeton").style.display == "none"){
		document.getElementById("divSaisieJeton").style.display = "inherit";
	} else {
		document.getElementById("divSaisieJeton").style.display = "none";
	}
	/* Fin Commande_08_2016 : Masquage de l'IBAN */
}

function envoiForm(){
	document.getElementById('frmJeton').submit();
}
/* Fin Commande_06_2016 : Confirmation par code de l'IBAN dans le suivi */

/* Début Commande_24_2016 : SuiviPVE - paiement des frais de gestion */
function validePaiement() {
	var ok = true;
	if (document.paiementForm.paiement.value == "") {
	      alert("Vous devez indiquer un mode de paiement.");
	      ok = false;
	   }
	return ok;
}
/* Fin Commande_24_2016 : SuiviPVE - paiement des frais de gestion */

