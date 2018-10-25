using System;
using Microsoft.EntityFrameworkCore.Metadata;
using Microsoft.EntityFrameworkCore.Migrations;

namespace TP3.Migrations
{
    public partial class CreationBDFilmRating : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateTable(
                name: "T_E_COMPTE_CPT",
                columns: table => new
                {
                    CPT_ID = table.Column<int>(nullable: false)
                        .Annotation("SqlServer:ValueGenerationStrategy", SqlServerValueGenerationStrategy.IdentityColumn),
                    CPT_NOM = table.Column<string>(unicode: false, maxLength: 50, nullable: false),
                    CPT_PRENOM = table.Column<string>(unicode: false, maxLength: 50, nullable: false),
                    CPT_TELPORTABLE = table.Column<string>(type: "char(50)", nullable: true),
                    CPT_MEL = table.Column<string>(unicode: false, maxLength: 100, nullable: false),
                    CPT_PWD = table.Column<string>(unicode: false, maxLength: 64, nullable: true),
                    CPT_RUE = table.Column<string>(unicode: false, maxLength: 200, nullable: false),
                    CPT_CP = table.Column<string>(type: "char(5)", nullable: false),
                    CPT_VILLE = table.Column<string>(unicode: false, maxLength: 50, nullable: false),
                    CPT_PAYS = table.Column<string>(unicode: false, maxLength: 50, nullable: false),
                    CPT_LATITUDE = table.Column<float>(type: "real", nullable: true),
                    CPT_LONGITUDE = table.Column<float>(type: "real", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_T_E_COMPTE_CPT", x => x.CPT_ID);
                });

            migrationBuilder.CreateTable(
                name: "T_E_FILM_FLM",
                columns: table => new
                {
                    FLM_ID = table.Column<int>(nullable: false)
                        .Annotation("SqlServer:ValueGenerationStrategy", SqlServerValueGenerationStrategy.IdentityColumn),
                    FLM_TITRE = table.Column<string>(unicode: false, maxLength: 100, nullable: false),
                    FLM_SYNOPSIS = table.Column<string>(unicode: false, maxLength: 500, nullable: true),
                    FLM_DATEPARUTION = table.Column<DateTime>(nullable: false),
                    FLM_DUREE = table.Column<decimal>(type: "numeric(3,0)", nullable: false),
                    FLM_GENRE = table.Column<string>(unicode: false, maxLength: 30, nullable: false),
                    FLM_URLPHOTO = table.Column<string>(unicode: false, maxLength: 200, nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_T_E_FILM_FLM", x => x.FLM_ID);
                });

            migrationBuilder.CreateTable(
                name: "T_E_AVIS_AVI",
                columns: table => new
                {
                    CPT_ID = table.Column<int>(nullable: false),
                    FLM_ID = table.Column<int>(nullable: false),
                    AVI_DATE = table.Column<DateTime>(nullable: false, defaultValueSql: "getdate()"),
                    AVI_TITRE = table.Column<string>(unicode: false, maxLength: 100, nullable: false),
                    AVI_DETAIL = table.Column<string>(unicode: false, maxLength: 2000, nullable: false),
                    AVI_NOTE = table.Column<decimal>(type: "numeric(1)", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_T_E_AVIS_AVI", x => new { x.CPT_ID, x.FLM_ID });
                    table.ForeignKey(
                        name: "FK_AVI_CPT",
                        column: x => x.CPT_ID,
                        principalTable: "T_E_COMPTE_CPT",
                        principalColumn: "CPT_ID",
                        onDelete: ReferentialAction.Restrict);
                    table.ForeignKey(
                        name: "FK_AVI_FLM",
                        column: x => x.FLM_ID,
                        principalTable: "T_E_FILM_FLM",
                        principalColumn: "FLM_ID",
                        onDelete: ReferentialAction.Restrict);
                });

            migrationBuilder.CreateTable(
                name: "T_J_FAVORI_FAV",
                columns: table => new
                {
                    CPT_ID = table.Column<int>(nullable: false),
                    FLM_ID = table.Column<int>(nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_T_J_FAVORI_FAV", x => new { x.CPT_ID, x.FLM_ID });
                    table.ForeignKey(
                        name: "FK_FAV_CPT",
                        column: x => x.CPT_ID,
                        principalTable: "T_E_COMPTE_CPT",
                        principalColumn: "CPT_ID",
                        onDelete: ReferentialAction.Restrict);
                    table.ForeignKey(
                        name: "FK_FAV_FLM",
                        column: x => x.FLM_ID,
                        principalTable: "T_E_FILM_FLM",
                        principalColumn: "FLM_ID",
                        onDelete: ReferentialAction.Restrict);
                });

            migrationBuilder.CreateIndex(
                name: "IX_T_E_AVIS_AVI_FLM_ID",
                table: "T_E_AVIS_AVI",
                column: "FLM_ID");

            migrationBuilder.CreateIndex(
                name: "IX_T_E_COMPTE_CPT_CPT_MEL",
                table: "T_E_COMPTE_CPT",
                column: "CPT_MEL",
                unique: true);

            migrationBuilder.CreateIndex(
                name: "IX_T_J_FAVORI_FAV_FLM_ID",
                table: "T_J_FAVORI_FAV",
                column: "FLM_ID");
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "T_E_AVIS_AVI");

            migrationBuilder.DropTable(
                name: "T_J_FAVORI_FAV");

            migrationBuilder.DropTable(
                name: "T_E_COMPTE_CPT");

            migrationBuilder.DropTable(
                name: "T_E_FILM_FLM");
        }
    }
}
