using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace TP3.Models.EntityFramework
{
    public class FilmsContext : DbContext
    {
        public FilmsContext()
        {
        }

        public FilmsContext(DbContextOptions<FilmsContext> options)
            : base(options)
        {
        }

        public virtual DbSet<Avis> Avis { get; set; }
        public virtual DbSet<Compte> Compte { get; set; }
        public virtual DbSet<Favori> Favori { get; set; }
        public virtual DbSet<Film> Film { get; set; }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            if (!optionsBuilder.IsConfigured)
            {
                // warning To protect potentially sensitive information
                // in your connection string
                //you should move it out of source code
                // See http://go.microsoft.com/fwlink/?LinkId=723263 for guidance on storing connection strings.
                optionsBuilder.UseSqlServer(
                    "Server=localhost\\SQLEXPRESS; Database=Films;Trusted_Connection=True;"
                );
            }
        }
        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            // Entité Avis
            modelBuilder.Entity<Avis>(entity =>
            {
                // PKs
                entity.HasKey(c => new { c.CompteId, c.FilmId });

                //AVI_DATE DateAvis DateTime -> DateTime not null
                // valeur par défaut Date du jour(default getdate()).
                entity.Property(b => b.DateAvis)
                    //.HasDefaultValue(DateTime.Now);
                    .HasDefaultValueSql("getdate()");

                // unicodes
                entity.Property(e => e.Titre).IsUnicode(false);
                entity.Property(e => e.Detail).IsUnicode(false);

                // foreign keys
                entity.HasOne(d => d.CompteAvis)
                    .WithMany(p => p.AvisCompte)
                    .HasForeignKey(d => d.CompteId)
                    .OnDelete(DeleteBehavior.ClientSetNull)
                    .HasConstraintName("FK_AVI_CPT");
                entity.HasOne(d => d.FilmAvis)
                    .WithMany(p => p.AvisFilm)
                    .HasForeignKey(d => d.FilmId)
                    .OnDelete(DeleteBehavior.ClientSetNull)
                    .HasConstraintName("FK_AVI_FLM");
            });

            // Entité Compte
            modelBuilder.Entity<Compte>(entity =>
            {

                // CPT_MEL Mel string -> Varchar(100) not null
                // Doit être unique(clé unique)
                entity.HasIndex(i => i.Mel)
                    .IsUnique();

                // unicodes
                entity.Property(e => e.Nom).IsUnicode(false);
                entity.Property(e => e.Prenom).IsUnicode(false);
                entity.Property(e => e.Mel).IsUnicode(false);
                entity.Property(e => e.Pwd).IsUnicode(false);
                entity.Property(e => e.Rue).IsUnicode(false);
                entity.Property(e => e.Ville).IsUnicode(false);
                entity.Property(e => e.Pays).IsUnicode(false);
            });

            // Entité Favori
            modelBuilder.Entity<Favori>(entity =>
            {
                // PKs
                entity.HasKey(c => new { c.CompteId, c.FilmId });

                // foreign keys
                entity.HasOne(d => d.CompteFavori)
                    .WithMany(p => p.FavoriCompte)
                    .HasForeignKey(d => d.CompteId)
                    .OnDelete(DeleteBehavior.ClientSetNull)
                    .HasConstraintName("FK_FAV_CPT");
                entity.HasOne(d => d.FilmFavori)
                    .WithMany(p => p.FavoriFilm)
                    .HasForeignKey(d => d.FilmId)
                    .OnDelete(DeleteBehavior.ClientSetNull)
                    .HasConstraintName("FK_FAV_FLM");
            });

            // Entité Film
            modelBuilder.Entity<Film>(entity =>
            {
                entity.Property(e => e.Titre).IsUnicode(false);
                entity.Property(e => e.Synopsis).IsUnicode(false);
                entity.Property(e => e.Genre).IsUnicode(false);
                entity.Property(e => e.UrlPhoto).IsUnicode(false);
            });

            //TODO add unicode on strings
        }
    }
}
