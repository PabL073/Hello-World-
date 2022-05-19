#include "idocument.h"
#include "document_log.h"
#include "document_uniqueuser.h"
#include "document_register.h"
#include "document_passwordreset.h"
#include "document_list_recipes.h"
#include "document_access_recipe.h"
#include "document_add_review.h"
#include "document_add_nota.h"
#include "document_delete_recipe.h"
#include "document_favorites.h"
#include "document_add_favorite.h"
#include "document_uniquemail.h"
#include "document_delete_favorite.h"
#include "document_add_recipe.h"
#include "document_top_recipe.h"
#include "document_send_name.h"
#include "document_send_photo.h"

IDocument* Factory_Document::Create_LogInstance(const QString& str)
{
    return new Document_Log(str);
};

IDocument* Factory_Document::Create_UniqueUserInstance(const QString& str)
{
    return new Document_UniqueUser(str);
}

IDocument* Factory_Document::Create_UniqueMailInstance(const QString& str)
{
    return new document_uniquemail(str);
}

IDocument* Factory_Document::Create_RegisterInstance(const QString& lastname,const QString& firstname,const QString& email, const QString& username,const QString& password,const QString& account,const QString& answer)
{
    return new Document_Register(lastname,firstname,email,username,password,account,answer);
}

IDocument* Factory_Document::Create_PasswordResetInstance(const QString& str)
{
    return  new Document_PasswordReset(str);
}

IDocument* Factory_Document::Create_ListRecipesInstance(QString& str,int col0, int col1)
{
    return  new Document_List_Recipes(str,col0,col1);
}

IDocument* Factory_Document::Create_AccessRecipeInstance(const QString& str)
{
    return  new Document_Access_Recipe(str);
}

IDocument* Factory_Document::Create_AddReviewInstance(const QString& str)
{
    return  new  Document_Add_Review(str);
}

IDocument* Factory_Document::Create_AddNotaInstance(const QString& str)
{
    return  new  Document_Add_Nota(str);
}

IDocument* Factory_Document::Create_DeleteRecipeInstance(const QString& str)
{
    return  new  Document_Delete_Recipe(str);
}

IDocument*  Factory_Document::Create_FavoritesInstance(const QString& str)
{
     return  new  document_favorites(str);
}

IDocument*  Factory_Document::Create_AddFavoriteInstance(const QString& str)
{
     return  new  Document_Add_Favorite(str);
}

IDocument*  Factory_Document::Create_DeleteFavoriteInstance(const QString& str)
{
     return  new  Document_Delete_Favorite(str);
}

IDocument*  Factory_Document::Create_AddRecipeInstance(const QString& str)
{
     return  new  Document_add_recipe(str);
}

IDocument*  Factory_Document::Create_TopRecipeInstance()
{
     return  new  Document_Top_Recipe();
}

IDocument*  Factory_Document::Create_SendNameInstance(const QString& str)
{
     return  new  Document_Send_Name(str);
}

IDocument*  Factory_Document::Create_SendPhotoInstance(const QString& str)
{
     return  new  document_send_photo(str);
}
